#include "random_utils.hpp"
#include <cstdlib>
#include <iostream>
#include "vec3.hpp"

float random_float() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

Vec3 random_unit_vector() {
    while (true) {
        float x = 2*random_float()-1;
        float y = 2*random_float()-1;
        float z = 2*random_float()-1;
        float radius = x*x + y*y + z*z;
        if (radius <= 1) {
            Vec3 random_vec = Vec3(x, y, z);
            return unit_vector(random_vec);
        }
    }
}
