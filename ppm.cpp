
#include "ray.h"
#include "glm/glm.hpp"
#include "color.h"

#include <iostream>


bool hit_sphere(const glm::vec3 center, double radius, const ray& r) {
   //(𝐏+𝑡𝐔−𝐂)⋅(𝐏+𝑡𝐔−𝐂)=𝑟2 i.e.(𝐏−𝐂)⋅(𝐏−𝐂)−𝑟2+2𝑡𝐔⋅(𝐏−𝐂)+𝑡2(𝐔⋅𝐔)=0

    // calculate dist from ray's origin to center of sphere
    glm::vec3 sph = r.origin() - center;

    // calculate the quadratic equation of the intersection of sphere with ray
    auto a =  glm::dot(r.direction(), r.direction());
    auto b = glm::dot(2.0f * sph, r.direction());
    auto c = glm::dot(sph, sph) - radius*radius;
    // calculate the discriminant
    auto discriminant = b*b - 4*a*c;

    //calculating surface normals
    // shirley doesn't explain this math but also i should remember this but here is just a refresher for dummies 
    // it's straightforward to proce that every point on a unit sphere is also the normal vector on that sphere
    // ok not so straightforward just tedious not hard https://mathworld.wolfram.com/NormalVector.html
    // this is just given by sph value / radius which is technically sph value / sqrt(sph value) in the case that it's not a unit sphere

    // the normal vector is the vector perpendicular to the tangent plane of the sphere at that point
    // the tangent plane is the plane that touches the sphere at that point
    // ok so now we move on to the math

    // i understand that the way we did it in the book allows us to get a sense of the 3Dness of the sphere


    return (discriminant > 0); 

}

glm::vec3 ray_color(const ray& r) {
    glm::vec3 unit_direction = glm::normalize(r.direction());
    float t = 0.5*(unit_direction.y + 1.0);
    glm::vec3 white = glm::vec3(1.0, 1.0, 1.0);
    glm::vec3 pink = glm::vec3(1.0, 0.75, 0.79);
    glm::vec3 blue = glm::vec3(0.5, 0.7, 1.0);

    if (hit_sphere(glm::vec3(0,0,1), 0.25, r)) {
        return blue;
    };
  
    return (1.f-t)*white + t*pink;
}



int main() {

    //setting up img dimentions
    //const int image_width = 256;
    //const int image_height = 256;
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;

    // height is width/aspect ratio
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    //now setting up camera view
    //viewport is 2 units high
    // the viewport is what the camera sees, essentially the projection of a 3d scene in 2d
    // think pinhole camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    // focal length is the distance between the camera and the viewport
    auto focal_length = 1.0;

    auto origin = glm::vec3(0, 0, 0);
    auto horizontal = glm::vec3(viewport_width, 0, 0);
    auto vertical = glm::vec3(0, viewport_height, 0);
    // using lower left corner as the origin of the viewport
    // this is bec the viewport is centered at the origin - just arbitrarily picked a corner
    auto lower_left_corner = origin - horizontal/2.f - vertical/2.f - glm::vec3(0, 0, focal_length);

    //RENDERING IMG
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        // flush allows me to see render progressing inspite of errors in the code !
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
           
            float u = double(i) / (image_width-1);
            float v = double(j) / (image_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
             
            glm::vec3 pixel_color = ray_color(r);
            wrt_clr(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}