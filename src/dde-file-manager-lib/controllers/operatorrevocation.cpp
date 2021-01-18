/*
 * Copyright (C) 2017 ~ 2017 Deepin Technology Co., Ltd.
 *
 * Author:     zccrs <zccrs@live.com>
 *
 * Maintainer: zccrs <zhangjide@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "operatorrevocation.h"
#include "dfmeventdispatcher.h"
#include "models/trashfileinfo.h"
#include "dbusinterface/revocationmgr_interface.h"
#include <QDBusConnection>
#include <unistd.h>

DFM_BEGIN_NAMESPACE

class OperatorRevocationPrivate : public OperatorRevocation
{public: OperatorRevocationPrivate(){}};
Q_GLOBAL_STATIC(OperatorRevocationPrivate, _dfm_or)

OperatorRevocation *OperatorRevocation::instance()
{
    return _dfm_or;
}

bool OperatorRevocation::fmEvent(const QSharedPointer<DFMEvent> &event, QVariant *resultData)
{
    Q_UNUSED(resultData)

    switch (static_cast<DFMEvent::Type>(event->type())) {
    case DFMEvent::SaveOperator: {
        DFMSaveOperatorEvent *e = static_cast<DFMSaveOperatorEvent*>(event.data());

        if (e->iniaiator() && e->iniaiator()->property("_dfm_is_revocaion_event").toBool())
            return true;

        //fix bug44556、44632文件多次删除、剪切、撤销出现撤销失败（根据产品需求，限制最多连续撤销两次）
        if (REVOCATION_TIMES == operatorStack.count()) {
            operatorStack.pop_front();
        }
        operatorStack.push(*event.data());
        pushEvent();
        return true;
    }
    case DFMEvent::Revocation: {
        popEvent();
        return true;
    }
    case DFMEvent::CleanSaveOperator:
        operatorStack.clear();
        break;
    default:
        break;
    }

    return false;
}

OperatorRevocation::OperatorRevocation()
{

}

void OperatorRevocation::slotRevocationEvent()
{
    revocation();
}

bool OperatorRevocation::initialize()
{
    if (m_dbusInterface) {
        delete m_dbusInterface;
        m_dbusInterface = nullptr;
    }

    m_dbusInterface = new RevocationMgrInterface("com.deepin.filemanager.daemon",
                                                 "/com/deepin/filemanager/daemon/RevocationManager",
                                                 QDBusConnection::systemBus(),
                                                 this);

    if (!m_dbusInterface->isValid()) {
        qDebug() << "RevocationMgerInterface cannot linked!";

        delete m_dbusInterface;
        m_dbusInterface = nullptr;

        return false;
    }

    //! Get revocation event type.
    QString processName = getProcessName();
    if (processName == "dde-file-manager") {
        m_eventType = DFM_FILE_MGR_EVENT;
    } else {
        m_eventType = DFM_DESKTOP_EVENT;
    }

    //! Monitor revocation event from dde-file-manager-daemon
    QString sigName = "fmgrRevocationAction";
    if (m_eventType == DFM_DESKTOP_EVENT) {
        sigName = "deskRevocationAction";
    }

    bool bConnected = QDBusConnection::systemBus().connect(
                "com.deepin.filemanager.daemon",
                "/com/deepin/filemanager/daemon/RevocationManager",
                "com.deepin.filemanager.daemon.RevocationManager",
                sigName,
                this,
                SLOT(slotRevocationEvent()));
    if (!bConnected) {
        qDebug() << "connect to daemon failed!";
        return false;
    }

    qDebug() << "OperatorRevocation initialize successful.";
    return true;
}

bool OperatorRevocation::revocation()
{
    bool batch_mode = false;

    batch_revocation:

    if (operatorStack.isEmpty())
        return true;

    DFMSaveOperatorEvent e = dfmevent_cast<DFMSaveOperatorEvent>(operatorStack.pop());

    if (e.split()) {
        if (batch_mode) {
            return true;
        } else {
            batch_mode = true;
            goto batch_revocation;
        }
    }

    const QSharedPointer<DFMEvent> new_event = e.event();

    new_event->setProperty("_dfm_is_revocaion_event", true);

    if (e.async())
        DFMEventDispatcher::instance()->processEventAsync(new_event);
    else
        DFMEventDispatcher::instance()->processEvent(new_event);

    if (batch_mode)
        goto batch_revocation;

    return true;
}

QString OperatorRevocation::getProcessName()
{
    char processPath[MAX_FILE_NAME_CHAR_COUNT] = {0};
    ssize_t ret = readlink("/proc/self/exe", processPath, sizeof(processPath));
    if (ret == -1) {
        qDebug() << "readlink error";
        return "";
    }
    DUrl url(processPath);
    return url.fileName();
}

void OperatorRevocation::pushEvent()
{
    if (m_dbusInterface && m_dbusInterface->isValid()) {
        m_dbusInterface->pushEvent(m_eventType);
    } else {
        bool bSuccess = initialize();
        if (bSuccess) {
            m_dbusInterface->pushEvent(m_eventType);
        }
    }
}

void OperatorRevocation::popEvent()
{
    if (m_dbusInterface && m_dbusInterface->isValid()) {
        m_dbusInterface->popEvent();
    } else {
        bool bSuccess = initialize();
        if (bSuccess) {
            m_dbusInterface->popEvent();
        } else {
            revocation();
        }
    }
}



DFM_END_NAMESPACE