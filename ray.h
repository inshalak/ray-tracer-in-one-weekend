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

};





  



#endif