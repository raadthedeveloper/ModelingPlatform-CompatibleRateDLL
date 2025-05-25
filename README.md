
# Rate Selection DLL

![License](https://img.shields.io/badge/license-All--Rights--Reserved-red)
![Platform](https://img.shields.io/badge/platform-Windows%2032--bit-blue)
![Build](https://img.shields.io/badge/build-manual-lightgrey)
![Language](https://img.shields.io/badge/language-C++-blue)
![Use Case](https://img.shields.io/badge/use--case-Actuarial%20Modeling-purple)

This project contains a native DLL build component intended for integration with actuarial modeling platforms such as Moody’s AXIS.  
**Precompiled DLL not included** to preserve generality and due to the absence of sample input data.

A native C++ DLL that performs actuarial rate lookups based on policy characteristics.  
Designed for use in modeling platforms that support external DLL integration.

---

## Author

**Raad Fakhrian**  
[🔗 GitHub](https://github.com/raadthedeveloper) | [🔗 LinkedIn](https://linkedin.com/in/raadfakhrian)

---

## Windows DLL for Actuarial Rate Selection

A Windows-based native DLL designed to demonstrate how custom logic (e.g., rate selection based on gender and smoker status) can be embedded in external libraries for use in actuarial modeling platforms that support DLL integration.

---

## Disclaimer

This repository contains an independent, generic example of DLL integration for actuarial process optimization.  
It was developed for educational and noncommercial purposes and does not contain any proprietary, confidential, or employer-specific information.  
This project is not affiliated with any employer or third-party software vendor.

---

## Overview

This implementation demonstrates a native C++ DLL interface for high-performance actuarial computations.  
By using precompiled rate logic and cache-friendly memory access patterns (e.g., fixed-size array lookups), it illustrates how native code can reduce the runtime overhead of interpreted modeling environments.  
Users can adapt the logic to integrate with their own modeling platforms that support DLLs or external library hooks.

---

## License

This project is provided for educational purposes only.  
**All rights reserved — no license is granted for reuse or redistribution.**  
See the [LICENSE.txt](./LICENSE) file for full details.

---

## Prerequisites

### Windows

- MinGW-w64 (`i686-w64-mingw32-g++` compiler for 32-bit)
- Windows operating system

### macOS

- MinGW-w64 (`i686-w64-mingw32-g++` compiler for 32-bit)  
  You can install it using Homebrew:

```bash
brew install mingw-w64
```

---

## Build

Build scripts for Windows (`build.bat`) and cross-compilation on macOS (`CMakeLists.txt`) are included in the repo.

---

## Building the DLL

### Windows

1. Open Command Prompt in the project directory  
2. Run the build script:

```batch
build.bat
```

3. The DLL will be created as `rate.dll`

### macOS

1. Open Terminal in the project directory  
2. Run the following command:

```bash
i686-w64-mingw32-g++ -O2 -Wall -fms-extensions -shared -o rate.dll rate.cpp -DRATE_EXPORT
```

3. The DLL will be created as `rate.dll`

---

## Exported Functions

The DLL exports two functions:

1. `GetRate@8`
   - **Parameters**:
     - `policyInfo`: `const char*` (input string containing policy information)
     - `rate`: `double*` (output parameter for the rate)
   - **Returns**: `int` (0 for success, -1 for invalid policy, -2 for invalid combination)

2. `ValidateClass@4`
   - **Parameters**:
     - `genderSmoker`: `const char*` (input string containing gender/smoker code)
   - **Returns**: `int` (0 for success, -1 for invalid policy, -2 for invalid combination)

---

## Valid Gender/Smoker Combinations

- `"MN"`: Male Non-smoker  
- `"MS"`: Male Smoker  
- `"FN"`: Female Non-smoker  
- `"FS"`: Female Smoker  

---

## Notes

- The DLL is built for 32-bit Windows systems  
- When building on macOS, the resulting DLL will still be compatible with 32-bit Windows  
- The build process uses MinGW-w64's 32-bit toolchain (`i686-w64-mingw32`) to ensure compatibility

---

## Next Project

I am currently working on accelerating data pipelines within actuarial modeling environments.  
This project focuses on optimizing ETL workflows and improving data integration performance to support large-scale actuarial analytics with enhanced speed and scalability.
