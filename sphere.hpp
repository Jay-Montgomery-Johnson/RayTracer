#ifndef sphere
#define sphere

#include "vec3.hpp"
#include "ray.hpp"

struct hit_record {
    Vec3 intersection_point;
    Vec3 normal;
    float t;//the ray length parameter
};

class Sphere {
private:
    Vec3 center;
    float radius;
public:
    Sphere(Vec3 c, float r);

    bool hit(Ray& ray, float t_min, float t_max, hit_record& rec);

};

#endif