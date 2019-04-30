#include "sphere.h"

#include <cmath>

#include  "../bsdf.h"
#include "../misc/sphere_drawing.h"

namespace CGL { namespace StaticScene {

bool Sphere::test(const Ray& r, double& t1, double& t2) const {

  // TODO (Part 1.4):
  // Implement ray - sphere intersection test.
  // Return true if there are intersections and writing the
  // smaller of the two intersection times in t1 and the larger in t2.

  
  return false;


}

bool Sphere::intersect(const Ray& r) const {

  // TODO (Part 1.4):
  // Implement ray - sphere intersection.
  // Note that you might want to use the the Sphere::test helper here.
    double a = dot(r.d, r.d);
    double b = 2 * dot((r.d - this->o), r.d);
    double c = dot((r.d - this->o), (r.d - this->o)) - r2;
    double det = b * b - 4 * a * c;
    if (det > 0) {
        double t1 = (-b - sqrt(det))/ (2*a);
        double t2 = (-b + sqrt(det))/ (2*a);
        if (t1 > r.min_t and t1 < r.max_t) {
            r.max_t = t1;
            return true;
        }
        else if (t2 > r.min_t and t2 < r.max_t){
            r.max_t = t2;
            return true;
        }
    }
    return false;
        

}

bool Sphere::intersect(const Ray& r, Intersection *i) const {

  // TODO (Part 1.4):
  // Implement ray - sphere intersection.
  // Note again that you might want to use the the Sphere::test helper here.
  // When an intersection takes place, the Intersection data should be updated
  // correspondingly.
    double a = dot(r.d, r.d);
    double b = 2 * dot((r.o - this->o), r.d);
    double c = dot((r.o - this->o), (r.o - this->o)) - r2;
    double det = b * b - 4 * a * c;
    if (det > 0) {
        //std::cout<< det << endl;

        double t1 = (-b - sqrt(det))/ (2*a);
        double t2 = (-b + sqrt(det))/ (2*a);
        if (t1 > r.min_t and t1 < r.max_t) {
            r.max_t = t1;
            i->t = t1;
            i->n = normal(r.o + t1 * r.d);
            i->primitive = this;
            i->bsdf = get_bsdf();
            return true;
        }
        else if (t2 > r.min_t and t2 < r.max_t){
            r.max_t = t2;
            i->t = t2;
            i->n = normal(r.o + t2 * r.d);
            i->primitive = this;
            i->bsdf = get_bsdf();
            
            return true;
        }
    }
    //i->bsdf = get_bsdf();
    
    return false;
  
  
  return false;

  
}

void Sphere::draw(const Color& c, float alpha) const {
  Misc::draw_sphere_opengl(o, r, c);
}

void Sphere::drawOutline(const Color& c, float alpha) const {
    //Misc::draw_sphere_opengl(o, r, c);
}


} // namespace StaticScene
} // namespace CGL