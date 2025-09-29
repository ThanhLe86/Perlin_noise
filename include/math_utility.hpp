#ifndef __MATH_UTILITY__H__
#define __MATH_UTILITY__H__
#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <random>
#include "pcg_random.hpp"

//combining numbers experiment
// Combining inoputs cause idk
uint32_t max = 4294967295;

uint32_t combine(uint32_t x, uint32_t y) {
    // uint32_t combined = (x * 1664525) ^ y;
    // return combined;
    return (x << 16) | (y & 0xFFFF);
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

float easing(float x) {
    return (3 * pow(x, 2) - 2 * pow(x, 3));
}

inline uint32_t random_uint(){
    pcg32 rng(pcg_extras::seed_seq_from<std::random_device>{});
    uint32_t rand_res = rng(max);
    return rand_res;
}

inline float random_float(int min, int max){
    uint32_t rand_num = random_uint();
    float rand_scaled = (static_cast<float> (rand_num)) / ::max; // address global variable (scope resolution)

    return min + (max - min)*rand_scaled;;
}


#endif  //!__MATH_UTILITY__H__
