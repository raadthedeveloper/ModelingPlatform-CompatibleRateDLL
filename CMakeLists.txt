# Author: Raad Fakhrian
# [github.com/raadthedeveloper](https://github.com/raadthedeveloper)

# This CMake configuration is for educational demonstration purposes only.
# No proprietary or confidential information is included.

# Programming on MacOS but building for Windows
cmake_minimum_required(VERSION 3.10)
project(rate)

# Set Windows cross-compilation
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)

# Enable MS extensions for __declspec
add_compile_options(-fms-extensions)

add_library(rate SHARED
    rate.cpp
    rate.h
)

target_compile_definitions(rate PRIVATE RATE_EXPORT) 