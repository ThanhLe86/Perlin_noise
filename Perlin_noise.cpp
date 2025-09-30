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

            //gradient vectors
            vec2 g00 = vec2(random_float(x_floor), random_float(y_floor));
            vec2 g01 = vec2(random_float(x_floor), random_float(y_ceil));
            vec2 g10 = vec2(random_float(x_ceil), random_float(y_floor));
            vec2 g11 = vec2(random_float(x_ceil), random_float(y_ceil));

            //direction vectors
            vec2 d00 = vec2(x - x_floor, y - y_floor);
            vec2 d01 = vec2(x - x_floor, y - y_ceil);
            vec2 d10 = vec2(x - x_ceil, y - y_floor);
            vec2 d00 = vec2(x - x_ceil, y - y_ceil);


            
        }
    }

    std::clog << "\rDone. \n";
    return 0;
}
