#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.hpp"
#include "vec3.hpp"
#include <memory>

class Material;

struct hit_record {
    Vec3 intersection_point;
    Vec3 normal;
    std::shared_ptr<Material> material;
    float t;//the ray length parameter
};

class Material {
public:
    virtual bool scatter(Ray& r_in, hit_record& rec,Vec3& attenuation, Ray& scattered);
};

class Diffuse : public Material {
private:
    Vec3 albedo;
public:
    Diffuse(Vec3& a);//albedo

    bool scatter(Ray& r_in, hit_record& rec,Vec3& attenuation, Ray& scattered);
};

class Metal : public Material {
private:
    Vec3 albedo;
public:
    Metal(Vec3& a);//albedo

    bool scatter(Ray& r_in, hit_record& rec,Vec3& attenuation, Ray& scattered);
};


#endif