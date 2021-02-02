cmake_minimum_required(VERSION 3.0)
project(clogger C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

if (NOT TARGET clogger)
    add_custom_target(clogger)

    # Install
    install(FILES clogger.h DESTINATION include)
endif ()

