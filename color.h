#ifndef color.h
#define color.h
#include <glm/glm.hpp> // glm::vec3
#include <iostream>


// here we create a utility function that allows us to write a single pixel's color to any output file


void wrt_clr(std::ostream &out, glm::vec3 pixel_color) {
 out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';

}



#endif