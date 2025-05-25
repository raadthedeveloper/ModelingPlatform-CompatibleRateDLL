:: Author: Raad Fakhrian
:: [github.com/raadthedeveloper](https://github.com/raadthedeveloper)

:: This build script is provided for educational purposes only.
:: No proprietary or confidential information included.

@echo off
setlocal

:: Set compiler and flags for 32-bit with maximum optimization
set CC=i686-w64-mingw32-g++
set CFLAGS=-O3 -march=i686 -mtune=generic -ffast-math -fomit-frame-pointer -Wall -fms-extensions -shared -o rate.dll

:: To compile for 64-bit, use:
:: set CC=x86_64-w64-mingw32-g++

:: Compile the DLL
%CC% %CFLAGS% rate.cpp -DRATE_EXPORT

echo Build complete. Check for rate.dll 