#ifndef __MATH_UTILITY__H__
#define __MATH_UTILITY__H__
#include <cstdint>
#include <cmath>
#include "pcg_random.hpp"

//combining numbers experiment
// Combining inoputs cause idk
uint32_t max = 4294967295;

uint32_t combine(uint32_t x, uint32_t y) {
    // uint32_t combined = (x * 1664525) ^ y;
    // return combined;
    return (x << 16) | (y & 0xFFFF);
}

//Combining input with Cantor pairing
uint32_t Cantor_pairing(float x, float y) {
    uint32_t x_int = static_cast<uint32_t>(x * 65536.0f);
    uint32_t y_int = static_cast<uint32_t>(y * 65536.0f);
    return 1/2 * (x_int + y_int) * (x_int + y_int + 1) + y_int;
    
}

uint32_t hash(uint32_t seed){
    pcg32 rng(seed);
    uint32_t digest = rng();
    return digest;
}

float lerp (float val1, float val2, float fraction) {   
    //Float conversion to prevent integer division 
    return (val1 + fraction * ((val2  - val1))); 
}

#endif  //!__MATH_UTILITY__H__
