#ifndef hittable_list
#define hittable_list

#include <memory>
#include <vector>
#include "sphere.hpp"

class Hittable_list {
public:
    std::vector<std::shared_ptr<Sphere> > objects;

    Hittable_list();
    Hittable_list(std::shared_ptr<Sphere> object);

    void clear();

    void add(std::shared_ptr<Sphere> object);

    bool hit(Ray& current_ray, float t_min, float t_max, hit_record& rec);
};

#endif