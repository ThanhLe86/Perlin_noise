#include <iostream>
#include "math_utility.hpp"

int	main(int argc, char **argv)
{
    int image_height = 400;
    int image_width = 800;
    uint32_t max_int = 4294967295;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    //Pixel coordinates are supposed to be whole numbers, when addressing for noise generation, we scale them accordingly
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            //scaling coordinates, these values can be changed to your liking, lesser means more zoomed out, greater is the reversed
            float x = (float)i / 15.0f; // important (*)
            float y = (float)j / 15.0f;

            uint32_t x_floor = static_cast<uint32_t>(floor(x));
            uint32_t x_ceil = static_cast<uint32_t>(ceil(x));
            uint32_t y_floor = static_cast<uint32_t>(floor(y));
            uint32_t y_ceil = static_cast<uint32_t>(ceil(y));

            //combine the numbers 
            float n00 = (float)hash(combine(x_floor, y_floor)) / max_int;
            float n01 = (float)hash(combine(x_floor, y_ceil)) / max_int;
            float n10 = (float)hash(combine(x_ceil, y_floor))/ max_int;
            float n11 = (float)hash(combine(x_ceil, y_ceil)) / max_int;

            //bilinear interpolation
            float biline_lerp = lerp(lerp(n00, n10, x - x_floor), lerp(n01, n11, x - x_floor), y - y_floor);
            float eased_score = easing(biline_lerp);
            float rgbscore = eased_score * 256;

            std::cout << rgbscore << " " << rgbscore << " "  << rgbscore << '\n';
        }
    }

    std::clog << "\rDone. \n";
    return 0;
}
