#include "vec3.hpp"
#include <iostream>

Vec3::Vec3() {
    x = 0;
    y = 0;
    z = 0;
}

Vec3::Vec3(float input_x, float input_y, float input_z) {
    x = input_x;
    y = input_y;
    z = input_z;
}

void Vec3::print_vec() {
    std::cout << "x:" << x << " y:" << y << " z:" << z << "\n";
}
/*
float Vec3::x() {return array[0];}

float Vec3::y() {return array[1];}

float Vec3::z() {return array[2];}
*/