#include <iostream>
#include <fstream> // for file operations
#include "color.h" // for wrt_clr


int main() {
    // creating img specifications
    const int img_width = 256;
    const int img_height = 256;

    // creating render specifications
    std::ofstream file("img.ppm"); // Create and open the output file

    file << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = img_height - 1; j >= 0; --j) {
        // use std::flush here to ensure that the output is flushed to the console
        // the default is that it is stored in a buffer and outputted when the buffer is full
        // we want to flush the buffer every time we print a line
        // otherwise, the console will not update until the entire image is rendered
        // and the user will not see the progress which is bad if there's an error at some point
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < img_width; ++i) {
            // cast to double to ensure auto compiles as double
            // and then cast back to int to ensure you are colouring each distinct pixel, essentially 
            // we are weighting each pixel by its position in the image
            // getting a red corner, a green corner, and a blue corner
            // pretty standard cis 460 stuff
            glm::vec3 pixel_color(double(i)/(img_width-1), double(j)/(img_height-1), 0.25);
            wrt_clr(std::cout, pixel_color);
        }
    }

    file.close(); // close the output file when done
}
