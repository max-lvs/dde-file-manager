// SPDX-FileCopyrightText: 2021 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef COMPUTER_H
#define COMPUTER_H

#include "dfmplugin_computer_global.h"

#include <dfm-framework/dpf.h>

namespace dfmplugin_computer {
class Computer : public dpf::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.deepin.plugin.filemanager" FILE "computer.json")

    DPF_EVENT_NAMESPACE(DPCOMPUTER_NAMESPACE)
    // slots
    DPF_EVENT_REG_SLOT(slot_ContextMenu_SetEnable)   // TODO(xust) tmp solution, using GroupPolicy instead.
    DPF_EVENT_REG_SLOT(slot_AddDevice)
    DPF_EVENT_REG_SLOT(slot_RemoveDevice)
    DPF_EVENT_REG_SLOT(slot_ComputerView_Refresh) // TODO(xust) impl it.
    
    // signals
    DPF_EVENT_REG_SIGNAL(signal_Operation_OpenItem)
    DPF_EVENT_REG_SIGNAL(signal_ShortCut_CtrlN)
    DPF_EVENT_REG_SIGNAL(signal_ShortCut_CtrlT)
    DPF_EVENT_REG_SIGNAL(signal_ReportLog_MenuData)

    // hook
    DPF_EVENT_REG_HOOK(hook_ComputerView_ItemListFilter)
    DPF_EVENT_REG_HOOK(hook_ComputerView_ItemFilterOnAdd)
    DPF_EVENT_REG_HOOK(hook_ComputerView_ItemFilterOnRemove)

    // Plugin interface
public:
    virtual void initialize() override;
    virtual bool start() override;

protected Q_SLOTS:
    void onWindowOpened(quint64 windd);

private:
    void addComputerToSidebar();
    void regComputerCrumbToTitleBar();
    void regComputerToSearch();
    void bindEvents();
    void followEvents();
    void bindWindows();
};
}

#endif   // COMPUTER_H
