#include "hittable_list.hpp"
#include <memory>
#include <vector>
#include <iostream>
#include "sphere.hpp"

Hittable_list::Hittable_list() {}
Hittable_list::Hittable_list(std::shared_ptr<Sphere> object) { add(object); }

void Hittable_list::clear() { objects.clear(); }

void Hittable_list::add(std::shared_ptr<Sphere> object) {
    objects.push_back(object);
}

bool Hittable_list::hit(Ray& current_ray, float t_min, float t_max, hit_record& rec) {
    //hit_record temp_rec;
    bool did_hit = false;
    
    //for (int object=0 ; objects.size(); object++) {
    //    std::cout << object << " :";
    if (objects[0]->hit(current_ray, t_min, t_max, rec) || objects[1]->hit(current_ray, t_min, t_max, rec) || objects[2]->hit(current_ray, t_min, t_max, rec)) {
        did_hit = true;
    }
    //}
    //rec = temp_rec;
    return did_hit;
}

