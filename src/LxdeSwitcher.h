/******************************************************************************
    This file is part of WallpaperChanger
    Copyright (C) 2013 Timothy McCarthy

    WallpaperChanger is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    WallpaperChanger is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with WallpaperChanger.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef LXDESWITCHER_H_
#define LXDESWITCHER_H_

#include "Switcher.h"
#include "Wallpaper.h"
#include "SwitcherException.h"

/**
 * Class for switching the wallpaper in an LXDE desktop session.
 */
class LxdeSwitcher : public Switcher {
public:
    
    LxdeSwitcher();
    
    virtual ~LxdeSwitcher();

    /**
     * Switch the desktop wallpaper to the given wallpaper.
     */
    virtual void performSwitch(Wallpaper & wallpaper) throw
        (SwitcherException);
    
};

#endif /* LXDESWITCHER_H_ */
