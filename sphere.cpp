#include "sphere.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include <cmath>
#include <iostream>

Sphere::Sphere(Vec3 c, float r) {
    center = c; 
    radius = r;
}

bool Sphere::hit(Ray& current_ray, float t_min, float t_max, hit_record& rec) {
    Vec3 o = current_ray.get_origin();
    Vec3 d = current_ray.get_direction();
    Vec3 o_C = o - center;
    Vec3 d2 = d * 2;

    double a = dot_product(d, d);
    double b = dot_product(d2, o_C);
    double c = dot_product(o_C, o_C) - radius*radius;
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {return false;}
    else {
        double top = b + std::sqrt(discriminant);
        double bottom = 2 * a;
        double soln = - top/bottom;
        rec.t = soln;
        rec.intersection_point = current_ray.get_position(rec.t);
        rec.normal = rec.intersection_point - center;
        rec.normal = unit_vector(rec.normal);
        //std::cout << rec.t;
        return true;
    }
}
