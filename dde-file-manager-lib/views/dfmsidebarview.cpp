/*
 * Copyright (C) 2019 Deepin Technology Co., Ltd.
 *
 * Author:     Gary Wang <wzc782970009@gmail.com>
 *
 * Maintainer: Gary Wang <wangzichong@deepin.com>
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
#include "dfmsidebarview.h"

#include "dfmsidebaritem.h"

#include <QDebug>

DFM_BEGIN_NAMESPACE

DFMSideBarView::DFMSideBarView(QWidget *parent)
    : DListView (parent)
{
    setVerticalScrollMode(ScrollPerPixel);
    setIconSize(QSize(16, 16));
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    setMouseTracking(true);

    setDragDropMode(QAbstractItemView::InternalMove);
    setDragDropOverwriteMode(false);
}

void DFMSideBarView::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        startDrag(Qt::MoveAction);
        QPoint pt = mapFromGlobal(QCursor::pos());
        QRect rc = geometry();
        if (!rc.contains(pt)) {
            emit requestRemoveItem(); //model()->removeRow(currentIndex().row());
            return;
        }
    }

    DListView::mouseMoveEvent(event);
}

DFM_END_NAMESPACE
