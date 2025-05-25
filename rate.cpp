// Author: Raad Fakhrian
// [github.com/raadthedeveloper](https://github.com/raadthedeveloper)

// Note: This is a minimal, example implementation intended for educational use only.
// It does not reflect real actuarial rates or proprietary logic.

#include "rate.h"
#include <string>
#include <array>
#include <unordered_map>

// Using array for fixed-size lookup table - faster than map for small datasets, especially for cells with minimal policy count
// Aligned for optimal cache access
alignas(64) const std::array<std::pair<const char*, double>, 4> RATES = {{
    {"MN", 0},  // Male Non-smoker
    {"MS", 0},  // Male Smoker
    {"FN", 0},  // Female Non-smoker
    {"FS", 0}   // Female Smoker
}};

// Error codes
enum ErrorCodes {
    SUCCESS = 0,
    INVALID_POLICY = -1,
    INVALID_COMBINATION = -2
};

// Force inline for performance
__forceinline int __declspec(dllexport) __stdcall GetRate(const char* policyInfo, double* rate) {
    if (!policyInfo || !rate) return INVALID_POLICY;
    
    // Direct array access instead of map lookup
    for (const auto& pair : RATES) {
        if (policyInfo[0] == pair.first[0] && policyInfo[1] == pair.first[1]) {
            *rate = pair.second;
            return SUCCESS;
        }
    }
    
    *rate = 0.0;
    return INVALID_COMBINATION;
}

// Force inline for performance
__forceinline int __declspec(dllexport) __stdcall ValidateClass(const char* genderSmoker) {
    if (!genderSmoker) return INVALID_POLICY;
    
    // Direct array access instead of map lookup
    for (const auto& pair : RATES) {
        if (genderSmoker[0] == pair.first[0] && genderSmoker[1] == pair.first[1]) {
            return SUCCESS;
        }
    }
    
    return INVALID_COMBINATION;
} 