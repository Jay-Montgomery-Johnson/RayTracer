#ifndef sphere
#define sphere

#include "vec3.hpp"
#include "ray.hpp"
#include "material.hpp"
#include <memory>
#include "material.hpp"

class Sphere {
private:
    Vec3 center;
    float radius;
    std::shared_ptr<Material> mat;
public:
    Sphere(Vec3 c, float r, std::shared_ptr<Material> material);

    bool hit(Ray& ray, float t_min, float t_max, hit_record& rec);

};

#endif