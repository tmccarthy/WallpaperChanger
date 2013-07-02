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

#include <iostream>

#include "Driver.h"
#include "Switcher.h"

int main(int argc, char * argv[]) {

    try {
        Driver driver(argc, argv);
        driver.run();
    } catch (std::exception & e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
