#ifndef vec3
#define vec3

class Vec3 {
private:
    float x, y, z;
public:
    Vec3();
    Vec3(float input_x, float input_y, float input_z);

    void print_vec();
    
    float get_x();
    float get_y();
    float get_z();

    Vec3& operator+=(Vec3 &v);
    Vec3& operator*=(float v);
    Vec3& operator/=(float v);

    float length();
    float length_squared();
    
};

Vec3 operator+(Vec3 &u, Vec3 &v);
Vec3 operator-(Vec3 &u, Vec3 &v);
Vec3 operator*(Vec3 &u, Vec3 &v);
Vec3 operator*(Vec3 &u, double t);
Vec3 operator/(Vec3 &u, double t);

double dot_product(Vec3 &u, Vec3 &v);

Vec3 cross_product(Vec3 &u, Vec3 &v);

Vec3 unit_vector(Vec3 &u);

#endif