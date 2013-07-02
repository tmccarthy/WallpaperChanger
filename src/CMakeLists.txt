cmake_minimum_required (VERSION 2.8.9)
project (WallpaperChanger)

set(required_boost_components filesystem system)

find_package(Boost 1.49 COMPONENTS ${required_boost_components} REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )

set(wallpaperChanger_sources main.cpp Utility.cpp Driver.cpp Switcher.cpp 
UnknownSessionException.cpp SwitcherException.cpp CommandLineOptionException.cpp
SystemCommandException.cpp DesktopSession.cpp 
LxdeSwitcher.cpp XfceSwitcher.cpp Wallpaper.cpp)

add_executable(wallpaperChanger ${wallpaperChanger_sources})
target_link_libraries(wallpaperChanger ${Boost_LIBRARIES} )

install (TARGETS wallpaperChanger DESTINATION bin)