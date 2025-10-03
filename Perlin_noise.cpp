#include <iostream>
#include "math_utility.hpp"

int	main(int argc, char **argv)
{
    int image_height = 400;
    int image_width = 800;
    uint32_t max_int = 4294967295;
    float mapping[2][8] = {{1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 0.0, 0.0}, {1.0, 1.0, -1.0, -1.0, 0.0, 0.0, 1.0, -1.0}};


    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    //Pixel coordinates are supposed to be whole numbers, when addressing for noise generation, we scale them accordingly
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            //scaling coordinates, these values can be changed to your liking, lesser means more zoomed out, greater is the reversed
            float x = (float)i / 20.0f; // important (*)
            float y = (float)j / 20.0f;

            uint32_t x_floor = static_cast<uint32_t>(floor(x));
            uint32_t x_ceil = static_cast<uint32_t>(ceil(x));
            uint32_t y_floor = static_cast<uint32_t>(floor(y));
            uint32_t y_ceil = static_cast<uint32_t>(ceil(y));

            //gradient vectors
            int o00 = hash(combine(x_floor, y_floor)) % 8;
            int o01 = hash(combine(x_floor, y_ceil)) % 8;
            int o10 = hash(combine(x_ceil, y_floor)) % 8;
            int o11 = hash(combine(x_ceil, y_ceil)) % 8;


            //mapping the results to predefined coordinates => gradient vectors
            vec2 g00 = vec2(mapping[0][o00], mapping[1][o00]);
            vec2 g01 = vec2(mapping[0][o01], mapping[1][o01]);
            vec2 g10 = vec2(mapping[0][o10], mapping[1][o10]);
            vec2 g11 = vec2(mapping[0][o11], mapping[1][o11]);

            //direction vectors
            vec2 d00 = vec2(x - x_floor, y - y_floor);
            vec2 d01 = vec2(x - x_floor, y - y_ceil);
            vec2 d10 = vec2(x - x_ceil, y - y_floor);
            vec2 d11 = vec2(x - x_ceil, y - y_ceil);

            float dot00 = dot(g00, d00);
            float dot01 = dot(g01, d01);
            float dot10 = dot(g10, d10);
            float dot11 = dot(g11, d11);

            //smooth out the fraction part
            float x_fract = smootherstep(x - x_floor);
            float y_fract = smootherstep(y - y_floor);

            // float x_fract = x - x_floor;
            // float y_fract = y - y_floor;

            //bilinearly interpolate
            float rgb_score = lerp(lerp(dot00, dot10, x_fract), lerp(dot01, dot11, x_fract), y_fract);
            rgb_score = ((rgb_score + 1) / 2) * 256; //scale values to [0; 1] 
            std::cout << rgb_score << " " << rgb_score << " " << rgb_score << "\n";

            
        }
    }

    std::clog << "\rDone. \n";
    return 0;
}
