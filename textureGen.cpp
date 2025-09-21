#include <iostream>
#include "math_utility.hpp"

int	main(int argc, char **argv)
{
    int image_height = 400;
    int image_width = 800;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    //Learn more about scaling stuff up and down (*)
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            //scaling coordinates
            float x = (float)i * 0.05f; // important (*)
            float y = (float)j * 0.05f;

            //combine the numbers 
            uint32_t n00 = hash(fixed_point_rep(x, y));
            uint32_t n01 = hash(fixed_point_rep(x, y));
            uint32_t n10 = hash(fixed_point_rep(x, y));
            uint32_t n11 = hash(fixed_point_rep(x, y));

            //bilinear interpolation
            float biline_lerp = lerp(lerp(n00, n01, x - floor(x)), lerp(n01, n11, x - floor(x)), y - floor(y));

            std::cout << biline_lerp << ' ' << biline_lerp << ' ' << biline_lerp << '\n';
        }
    }

    std::clog << "\rDone. \n";
    return 0;
}
