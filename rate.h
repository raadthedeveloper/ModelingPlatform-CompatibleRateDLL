// Author: Raad Fakhrian
// [github.com/raadthedeveloper](https://github.com/raadthedeveloper)

// Note: This is a minimal, example implementation intended for educational use only.

#pragma once

#include <windows.h>

extern "C" {
    // Function to get the rate based on gender/smoker status
    int __declspec(dllexport) __stdcall GetRate(const char* policyInfo, double* rate);
    
    // Function to validate the gender/smoker combination
    int __declspec(dllexport) __stdcall ValidateClass(const char* genderSmoker);
} 