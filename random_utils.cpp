#include "random_utils.hpp"
#include <cstdlib>
#include <iostream>

float random_float() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

