#include "vec3.hpp"
#include <iostream>

int main() {
    std::cout << "Hello World \n";
    float x = 13;
    float y = 2;
    float z = 3;
    Vec3 point(x, y, z);
    point.print_vec();
    return 0;
}