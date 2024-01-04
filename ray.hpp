#ifndef ray
#define ray

#include "vec3.hpp"


class Ray {
private:
    Vec3 origin;
    Vec3 direction;
public:
    Ray();
    Ray(Vec3 o, Vec3 d);

    Vec3 get_position(float t);
    Vec3 get_origin();
    Vec3 get_direction();
};

#endif