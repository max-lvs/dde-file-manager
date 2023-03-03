// SPDX-FileCopyrightText: 2022 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef CANVASDBUSINTERFACE_H
#define CANVASDBUSINTERFACE_H

#include <QObject>
#include <QDBusContext>

namespace ddplugin_canvas {

class CanvasManager;
class CanvasDBusInterface : public QObject, public QDBusContext
{
    Q_OBJECT
public:
    explicit CanvasDBusInterface(CanvasManager *parent = nullptr);

signals:

public slots:
    void EnableUIDebug(bool enable);
    void Refresh(bool silent = true);
private:
    CanvasManager *manager = nullptr;
};
}
#endif // CANVASDBUSINTERFACE_H
