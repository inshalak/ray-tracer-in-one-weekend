
#include "ray.h"
#include "glm/glm.hpp"
#include "color.h"

#include <iostream>

glm::vec3 ray_color(const ray& r) {
    glm::vec3 unit_direction = glm::normalize(r.direction());
    float t = 0.5*(unit_direction.y + 1.0);
    glm::vec3 white = glm::vec3(1.0, 1.0, 1.0);
    glm::vec3 pink = glm::vec3(1.0, 0.75, 0.79);
   // glm::vec3 blue = glm::vec3(0.5, 0.7, 1.0);
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