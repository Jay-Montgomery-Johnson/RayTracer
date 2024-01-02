#ifndef camera
#define camera

#include "vec3.hpp"
#include "ray.hpp"
#include "stb_image.h"
#include "hittable_list.hpp"

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

    Vec3 ray_color(Ray current_ray, Hittable_list world, int num_rays, int ray_depth);
    Ray get_ray(int nx, int ny);
    Vec3 random_surrounding_point();
public:
    Camera();
    void render(Hittable_list world);
};

Vec3 get_color(float r, float g, float b);


//float hit_sphere(Vec3 C, float r, Ray ray);

#endif