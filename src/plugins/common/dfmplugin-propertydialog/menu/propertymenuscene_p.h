/*
 * Copyright (C) 2022 Uniontech Software Technology Co., Ltd.
 *
 * Author:     liqiang<liqianga@uniontech.com>
 *
 * Maintainer: liqiang<liqianga@uniontech.com>
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
#ifndef OPENWITHMENUSCENE_P_H
#define OPENWITHMENUSCENE_P_H

#include "propertymenuscene.h"

#include "interfaces/private/abstractmenuscene_p.h"

DPPROPERTYDIALOG_BEGIN_NAMESPACE
DFMBASE_USE_NAMESPACE

class PropertyMenuScenePrivate : public AbstractMenuScenePrivate
{
public:
    friend class PropertyMenuScene;
    explicit PropertyMenuScenePrivate(PropertyMenuScene *qq = nullptr);

private:
    void updateMenu(QMenu *menu);
};

DPPROPERTYDIALOG_END_NAMESPACE

#endif   // OPENWITHMENUSCENE_P_H
