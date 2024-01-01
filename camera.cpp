#include "camera.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "random_utils.hpp"
#include "stb_image.h"
#include "stb_image_write.h"
#include "hittable_list.hpp"
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
    Vec3 random_sample = random_surrounding_point();
    direction += random_sample;
    direction = direction - camera_position;


    Ray new_ray = Ray(camera_position, direction);
    return new_ray;
}

Vec3 Camera::ray_color(Ray current_ray, Hittable_list world, int num_rays) {
    float y_max = upper_left.get_y();
    
    //for (int i=0; world.objects.size(); i++) {
    hit_record rec;
    bool did_hit = world.hit(current_ray, 0, 10000, rec);

    if (did_hit) {
        Vec3 point_on_sphere = rec.intersection_point;
        Vec3 normal = rec.normal;
        float scaled_r = (0.5*(normal.get_x() + 1))/num_rays;
        float scaled_g = (0.5*(normal.get_y() + 1))/num_rays;
        float scaled_b = (0.5*(normal.get_z() + 1))/num_rays;
        return Vec3(scaled_r, scaled_g, scaled_b);
    }
    //}

    Vec3 current_direction = current_ray.get_direction();
    float y_ray = current_direction.get_y();
    float scaled_y = y_ray/y_max;
    float a = 0.5*(1 + scaled_y);

    Vec3 blue = Vec3(0.5f, 0.7f, 1.0f);
    Vec3 white = Vec3(1.0f, 1.0f, 1.0f);
    blue = blue * (1-a);
    white = white * a;
    white = blue + white;
    return white / num_rays;
}

void Camera::render(Hittable_list world) {
    int CHANNEL_NUM = 3;
    int rays_per_pixel = 100;
    uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

    int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
        for (int i = 0; i < width; ++i)
        {
            Vec3 color;
            for (int N=0; N<rays_per_pixel; N++){
                Ray current_ray = get_ray(i, j);
                Vec3 current_ray_color = ray_color(current_ray, world, rays_per_pixel);
                color += current_ray_color;
            }
            color = get_color(color.get_x(), color.get_y(), color.get_z());
            //if (color.get_x() > 255) {color = Vec3(254.99f, color.get_y(), color.get_z());}
            //if (color.get_y() > 255) {color = Vec3(color.get_x(), 254.99f, color.get_z());}
            //if (color.get_z() > 255) {color = Vec3(color.get_x(), color.get_y(), 254.99f);}
            
            pixels[index++] = color.get_x(); //R
            pixels[index++] = color.get_y(); //G
            pixels[index++] = color.get_z(); //B
        }
    }
    stbi_write_png("stbpng1.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);
}

Vec3 Camera::random_surrounding_point() {
    float rand_x = random_float() - 0.5;
    float rand_y = random_float() - 0.5;
    Vec3 sample_x = dx * rand_x;
    Vec3 sample_y = dy * rand_y;
    return sample_x + sample_y;
    
}

Vec3 get_color(float r, float g, float b) {
    int ir = int(255.99 * r);
    int ig = int(255.99 * g);
    int ib = int(255.99 * b);
    return Vec3(ir, ig, ib);
}



/*
float hit_sphere(Vec3 C, float r, Ray new_ray) {
    Vec3 o = new_ray.get_origin();
    Vec3 d = new_ray.get_direction();
    Vec3 o_C = o - C;
    Vec3 d2 = d * 2;

    double a = dot_product(d, d);
    double b = dot_product(d2, o_C);
    double c = dot_product(o_C, o_C) - r*r;
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {return -1.0f;}
    else {
        double top = b + std::sqrt(discriminant);
        double bottom = 2 * a;
        double soln = - top/bottom;
        return soln;
    }
}*/