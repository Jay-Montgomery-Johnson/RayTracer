#include "material.hpp"
#include "ray.hpp"
#include "vec3.hpp"
#include "random_utils.hpp"

bool Material::scatter(Ray& r_in, hit_record& rec,Vec3& attenuation, Ray& scattered) {return true;}


Diffuse::Diffuse(Vec3& a) {
    albedo = a;
}

bool Diffuse::scatter(Ray& r_in, hit_record& rec,Vec3& attenuation, Ray& scattered) {
    Vec3 r_vec = random_unit_vector();
    //std::cout << " unit vec: " << dot_product(normal, r_vec);
    if (dot_product(rec.normal, r_vec) < 0) {
        r_vec = Vec3(-r_vec.get_x(),-r_vec.get_y(),-r_vec.get_z());
    }
    scattered = Ray(rec.intersection_point, r_vec);
    attenuation = albedo;
    return true;
}

Metal::Metal(Vec3& a) {
    albedo = a;
}

bool Metal::scatter(Ray& r_in, hit_record& rec,Vec3& attenuation, Ray& scattered) {
    Vec3 in_dir = r_in.get_direction();
    Vec3 reflected = rec.normal*(dot_product(rec.normal, in_dir)*2);
    reflected = in_dir - reflected;
    scattered = Ray(rec.intersection_point, reflected);
    attenuation = albedo;
    return true;
}