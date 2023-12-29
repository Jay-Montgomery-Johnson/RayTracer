#ifndef camera
#define camera

#include "vec3.hpp"
#include "ray.hpp"
#include "stb_image.h"

class Camera {
private:
    int width;
    int height;
    Vec3 camera_position;
    Vec3 image_center_position;
    Vec3 image_center;
    Vec3 dx;
    Vec3 dy;
    Vec3 upper_left;

    Vec3 ray_color(int i, int j);
    Ray get_ray(int nx, int ny);
public:
    Camera();
    void render();
};

Vec3 get_color(float r, float g, float b);

bool hit_sphere(Vec3 C, float r, Ray ray);

#endif