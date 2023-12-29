#include "vec3.hpp"
#include <iostream>
#include <cmath>

Vec3::Vec3() {
    x = y = z = 0;
}

Vec3::Vec3(float input_x, float input_y, float input_z) {
    x = input_x;
    y = input_y;
    z = input_z;
}

void Vec3::print_vec() {
    std::cout << "x:" << x << " y:" << y << " z:" << z << "\n";
}

float Vec3::get_x() {return x;}

float Vec3::get_y() {return y;}

float Vec3::get_z() {return z;}

Vec3& Vec3::operator+=(Vec3 &v) {
    x += v.get_x();
    y += v.get_y();
    z += v.get_z();
    return *this;
}

Vec3& Vec3::operator*=(float v) {
    x *= v;
    y *= v;
    z *= v;
    return *this;
}

Vec3& Vec3::operator/=(float v) {
    return *this *= 1/v;
}

float Vec3::length() {
    int s = 2;
    return std::sqrt(std::pow(x, s) + std::pow(y, s) + std::pow(z, s));
}

float Vec3::length_squared() {
    int s = 2;
    return std::pow(x, s) + std::pow(y, s) + std::pow(z, s);
}

Vec3 operator+(Vec3 &u, Vec3 &v) {
    return Vec3(u.get_x() + v.get_x(), u.get_y() + v.get_y(), u.get_z() + v.get_z());
}

Vec3 operator-(Vec3 &u, Vec3 &v) {
    return Vec3(u.get_x() - v.get_x(), u.get_y() - v.get_y(), u.get_z() - v.get_z());
}

Vec3 operator*(Vec3 &u, Vec3 &v) {
    return Vec3(u.get_x() * v.get_x(), u.get_y() * v.get_y(), u.get_z() * v.get_z());
}

Vec3 operator*(Vec3 &u, double t) {
    return Vec3(u.get_x() * t, u.get_y() * t, u.get_z() * t);
}

Vec3 operator/(Vec3 &u, double t) {
    return Vec3(u.get_x() / t, u.get_y() / t, u.get_z() / t);
}

float dot_product(Vec3 &u, Vec3 &v) {
    return (u.get_x() * v.get_x()) + (u.get_y() * v.get_y()) + (u.get_z() * v.get_z());
}

Vec3 cross_product(Vec3 &u, Vec3 &v) {
    float i = u.get_y()*v.get_z() - u.get_z()*v.get_y();
    float j = u.get_z()*v.get_x() - u.get_x()*v.get_z();
    float k = u.get_x()*v.get_y() - u.get_y()*v.get_x();
    return Vec3(i, j, k);
}

Vec3 unit_vector(Vec3 &u) {
    return u / u.length();
}

