#include "vec3.hpp"
#include "ray.hpp"
#include "camera.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"
#include <iostream>
#include <memory>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    //+44 (0)117 4289400
    Hittable_list world;
    Vec3 center1 = Vec3(75, 37.5, 40);
    Vec3 center2 = Vec3(-75, 37.5, 40);
    Vec3 center3 = Vec3(0, -1000, 350);
    float radius = 75;
    world.add(std::make_shared<Sphere>(center1, radius));
    world.add(std::make_shared<Sphere>(center2, radius));
    radius = 1000;
    world.add(std::make_shared<Sphere>(center3, radius));
    Camera cam;
    cam.render(world);
    return 0;
}


/*
//How to write an image...
const int width = 200;
const int height = 100;
#define CHANNEL_NUM 3

//NOTICE!! You have to use uint8_t array to pass in stb function 
// Because the size of color is normally 255, 8bit.
// If you don't use this one, you will get a weird imge.
uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

int index = 0;
    for (int j = height - 1; j >= 0; --j)
    {
    for (int i = 0; i < width; ++i)
    {
    float r = (float)i / (float)width;
    float g = (float)j / (float)height;
    float b = 0.2f;
    int ir = int(255.99 * r);
    int ig = int(255.99 * g);
    int ib = int(255.99 * b);

    pixels[index++] = ir;
    pixels[index++] = ig;
    pixels[index++] = ib;
    }
    }
 
    // if CHANNEL_NUM is 4, you can use alpha channel in png
    stbi_write_png("stbpng.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);

    // You have to use 3 comp for complete jpg file. If not, the image will be grayscale or nothing.
    stbi_write_jpg("stbjpg3.jpg", width, height, 3, pixels, 100);
    delete[] pixels;

    return 0;
*/

/*
// testing hte vec3 function
std::cout << "Hello World \n";
    float x = 1;
    float y = 2;
    float z = 3;
    Vec3 point(x, y, z);
    x = 5;
    y = 4;
    z = 3;
    Vec3 point2(x, y, z);
    x = y = z = 3;
    Vec3 point3(x, y, z);
    std::cout << "dot: ";
    float t1 = dot_product(point, point2);
    std::cout << t1;
    std::cout << "\n cross: ";
    Vec3 t2 = cross_product(point, point2);
    t2.print_vec();
    std::cout << "\n unit vector: " ;
    Vec3 t3 = unit_vector(point3);
    t3.print_vec();
    std::cout << "\n point*point2: ";
    Vec3 t4 = point * point2;
    t4.print_vec();
    std::cout << "\n point+point2: ";
    Vec3 t5 = point + point2;
    t5.print_vec();
    std::cout << "\n point-point2: ";
    Vec3 t6 = point - point2;
    t6.print_vec();
    std::cout << "\n point/2: ";
    Vec3 t7 = point/2;
    t7.print_vec();
*/