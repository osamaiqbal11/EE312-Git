cmake_minimum_required(VERSION 3.13)
project(Life)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Life
        .idea/encodings.xml
        .idea/Life.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Life.cbp
        cmake-build-debug/Makefile
        CMakeLists.txt
        life.c
        life.h
        life_driver.c
        makefile
        world.txt)
