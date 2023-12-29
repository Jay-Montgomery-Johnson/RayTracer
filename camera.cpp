#include "camera.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>
#include <cmath>

Camera::Camera() {
    //Image
    width = 400;
    height = 300;
    
    dx = Vec3(1, 0, 0);
    dy = Vec3(0, 1, 0);

    //camera position
    camera_position = Vec3(0, 0, -400);
    image_center = Vec3();

    //calculate the location of the upper left hand pixel
    float x_float = -width/2;
    float y_float = -height/2;
    upper_left = Vec3(x_float, y_float, 0);
}

Ray Camera::get_ray(int nx, int ny) {
    Vec3 x_change = dx * nx;
    Vec3 y_change = dy * ny;

    Vec3 direction = upper_left + x_change;
    direction += y_change;
    direction = direction - camera_position;

    Ray new_ray = Ray(camera_position, direction);
    return new_ray;
}

Vec3 Camera::ray_color(int i, int j) {
    float y_max = upper_left.get_y();
    Ray current_ray = get_ray(i, j);
    Vec3 red = get_color(1.0f, 0.2f, 0.2f);
    if (hit_sphere(Vec3(0, 0, 100), 50, current_ray)) { return red;}

    Vec3 current_direction = current_ray.get_direction();
    float y_ray = current_direction.get_y();
    float scaled_y = y_ray/y_max;
    float a = 0.5*(1 + scaled_y);

    Vec3 blue = get_color(0.5f, 0.7f, 1.0f);
    Vec3 white = get_color(1.0f, 1.0f, 1.0f);
    blue = blue * (1-a);
    white = white * a;
    return blue + white;
}

void Camera::render() {
    int CHANNEL_NUM = 3;
    uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        for (int i = 0; i < width; ++i)
        {
            Vec3 color = ray_color(i, j);

            pixels[index++] = color.get_x();
            pixels[index++] = color.get_y();
            pixels[index++] = color.get_z();
        }
    }
    std::cout << "hello there \n";
    stbi_write_png("stbpng1.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);
}

Vec3 get_color(float r, float g, float b) {
    int ir = int(255.99 * r);
    int ig = int(255.99 * g);
    int ib = int(255.99 * b);
    return Vec3(ir, ig, ib);
}

bool hit_sphere(Vec3 C, float r, Ray new_ray) {
    Vec3 o = new_ray.get_origin();
    Vec3 d = new_ray.get_direction();
    Vec3 o_C = o - C;
    Vec3 d2 = d * 2;

    float a = dot_product(d, d);
    float b = dot_product(d2, o_C);
    float c = dot_product(o_C, o_C) - r*r;

    float discriminant = std::sqrt(b*b - 4*a*c);
    return (discriminant >= 0);
}