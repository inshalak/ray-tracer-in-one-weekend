#include <iostream>

int main() {

    // creating img specifications
    const int img_width = 256;
    const int img_height = 256;

    // creating render specifications

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = img_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < img_width; ++i) {
            // cast to double to ensure auto compiles as double
            // and then cast back to int to ensure you are colouring each distinct pixel, essentially 
            // we are weighting each pixel by its position in the image
            // getting a red corner, a green corner, and a blue corner
            // pretty standard cis 460 stuff
            auto r = double(i) / (img_width-1);
            auto g = double(j) / (img_height-1);
            auto b = 0.25;

            // why cast to 255.999? because we are casting to int, which truncates
            // so we want to make sure we are truncating to 255, not 256
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}