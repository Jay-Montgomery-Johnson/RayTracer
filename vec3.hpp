#ifndef vec3
#define vec3


class Vec3 {
private:
    float x, y, z;
public:
    Vec3();
    Vec3(float input_x, float input_y, float input_z);

    void print_vec();
    /*
    float x();
    float y();
    float z();
    */
};

#endif