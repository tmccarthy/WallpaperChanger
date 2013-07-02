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

#include "Driver.h"

#include <unistd.h>
#include <string>
#include <cctype>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <iostream>

#include "Switcher.h"
#include "CommandLineOptionException.h"
#include "UnknownSessionException.h"

Driver::Driver(int argc, char * argv[]) throw (CommandLineOptionException) {
    parseFromCommandLineArguments(argc, argv, period_, doesRepeat_, 
            doesShuffle_, library_);
}

Driver::Driver(std::vector<Wallpaper> & library, int period, bool doesRepeat,
        bool doesShuffle) :
library_(library), period_(period), doesRepeat_(doesRepeat), doesShuffle_(
doesShuffle) {
}

Driver::~Driver() {
}

void Driver::run() throw (UnknownSessionException) {
    std::unique_ptr<Switcher> switcher = Switcher::generate();

    do {
        if (doesShuffle_) {
            std::random_shuffle(library_.begin(), library_.end());
        }

        std::vector<Wallpaper>::iterator libraryIt = library_.begin();

        while (libraryIt != library_.end()) {
            if (libraryIt != library_.begin()) {
                sleep(period_);
            }
            
            try {
                switcher->switchWallpaperTo(*libraryIt);
            } catch (SwitcherException & e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            
            libraryIt++;
        }

    } while (doesRepeat_);
}

int Driver::getPeriod() {
    return this->period_;
}

void Driver::setPeriod(int newPeriod) {
    this->period_ = newPeriod;
}

void Driver::parseFromCommandLineArguments(int argc, char* argv[], int& period, 
        bool& doesRepeat, bool& doesShuffle, std::vector<Wallpaper> library) {
    
    doesRepeat = DEFAULT_DOES_REPEAT;
    period = DEFAULT_PERIOD;
    doesShuffle = DEFAULT_DOES_SHUFFLE;

    int c;

    std::string getOptString = std::string() + SHUFFLE_OPTION_FLAG
            + REPEAT_OPTION_FLAG + PERIOD_OPTION_FLAG + std::string(":");
    opterr = 0;
    while ((c = getopt(argc, argv, getOptString.c_str())) != -1) {
        switch (c) {
            case REPEAT_OPTION_FLAG:
                doesRepeat = true;
                break;
            case SHUFFLE_OPTION_FLAG:
                doesShuffle = true;
                break;
            case PERIOD_OPTION_FLAG:
                try {
                    period = std::stoi(optarg);
                } catch (std::invalid_argument & e) {
                    throw CommandLineOptionException(
                            std::string("Invalid argument for option -") +
                            PERIOD_OPTION_FLAG);
                }
                if (period <= 0) {
                    throw CommandLineOptionException(
                            std::string("Invalid argument for option -") +
                            PERIOD_OPTION_FLAG);
                }
                break;
            case '?':
                if (optopt == PERIOD_OPTION_FLAG) {
                    throw CommandLineOptionException(
                            std::string("Option -") + PERIOD_OPTION_FLAG
                            + std::string(" missing argument"));
                } else {
                    throw CommandLineOptionException(
                            std::string("Unknown option -") + (char) optopt);
                }
                break;
        }
    }

    if (optind >= argc) {
        // If there are no non-option arguments
        throw CommandLineOptionException("No wallpapers given");
    } else {
        for (int i = optind; i < argc; i++) {
            std::unique_ptr<Wallpaper> newWallpaper(new Wallpaper(argv[i]));
            library_.push_back(*newWallpaper);
        }
    }
    
}