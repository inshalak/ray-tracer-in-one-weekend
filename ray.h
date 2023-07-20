// the ray file should define a ray's origin, and it's direction
// we're trying to fulfil the ray tracing equation p = At + B where p is a 3d position along a line in 3d
// A is the origin of the ray, B is the direction of the ray, and t is a real number

#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp> 
class ray {

    glm::vec3 orig;
    glm::vec3 dir; 
    // making constructors for ray class
    public:
    ray() {};
    ray(const glm::vec3& origin, const glm::vec3& direction) : orig(origin), dir(direction) {}

    glm::vec3 origin() const  { return orig;}
    glm::vec3 direction() const { return dir;}

    // using float instead of double for t because we don't need the precision
    // we're just using it to find the point along the ray atleast at the scale i'll use this for
    const glm::dvec3 at(float t) {
        return orig + dir*t;
    }

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

    return (discriminant > 0); 

}

};





  



#endif