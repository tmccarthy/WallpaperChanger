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

#ifndef DRIVER_H_
#define DRIVER_H_

#include <vector>

#include "CommandLineOptionException.h"
#include "UnknownSessionException.h"
#include "SwitcherException.h"
#include "Wallpaper.h"

class Driver {
public:
	static const int DEFAULT_PERIOD = 10;
	static const bool DEFAULT_DOES_REPEAT = false;
	static const bool DEFAULT_DOES_SHUFFLE = false;

	static const char REPEAT_OPTION_FLAG = 'r';
	static const char SHUFFLE_OPTION_FLAG = 's';
	static const char PERIOD_OPTION_FLAG = 'p';

	Driver(int argc, char * argv[]) throw(CommandLineOptionException);
	Driver(std::vector<Wallpaper> & library, int period = DEFAULT_PERIOD,
			bool doesRepeat = DEFAULT_DOES_REPEAT, bool doesShuffle = DEFAULT_DOES_SHUFFLE);
	virtual ~Driver();

	void run() throw (UnknownSessionException);

	int getPeriod();
	void setPeriod(int newPeriod);
	bool getDoesRepeat();
	void setDoesRepeat(bool doesRepeat);

private:
    
    void parseFromCommandLineArguments(int argc, char * argv[], int & period, 
            bool & doesRepeat, bool & doesShuffle, 
            std::vector<Wallpaper> library);
    
	std::vector<Wallpaper> library_;
	int period_;
	bool doesRepeat_;
	bool doesShuffle_;
};

#endif /* DRIVER_H_ */
