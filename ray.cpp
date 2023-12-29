#include "ray.hpp"
#include "vec3.hpp"

Ray::Ray() {
    origin = Vec3();
    direction = Vec3(1, 0, 0);
}

Ray::Ray(Vec3 o, Vec3 d) {
    origin = o;
    direction = d;
}

Vec3 Ray::get_position(float t) {
    Vec3 travel = direction * t;
    return origin + travel;
}