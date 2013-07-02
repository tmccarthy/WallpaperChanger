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

#include "Wallpaper.h"
#include "Utility.h"

#include <string>
#include <boost/filesystem.hpp>

namespace bfs = boost::filesystem;

Wallpaper::Wallpaper(std::string filePath) : filePath_(
        bfs::absolute(bfs::path(filePath)).string()) {
}

Wallpaper::~Wallpaper() {
}

std::string Wallpaper::getFilePath() {
    return filePath_;
}

bool Wallpaper::doesExist() {
    return bfs::exists(this->getFilePath());
}