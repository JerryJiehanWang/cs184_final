#include "triangle.h"

#include "CGL/CGL.h"
#include "GL/glew.h"

namespace CGL { namespace StaticScene {

Triangle::Triangle(const Mesh* mesh, size_t v1, size_t v2, size_t v3) :
    mesh(mesh), v1(v1), v2(v2), v3(v3) { }

BBox Triangle::get_bbox() const {

  Vector3D p1(mesh->positions[v1]), p2(mesh->positions[v2]), p3(mesh->positions[v3]);
  BBox bb(p1);
  bb.expand(p2); 
  bb.expand(p3);
  return bb;

}

bool Triangle::intersect(const Ray& r) const {

  // TODO (Part 1.3):
  // implement ray-triangle intersection
  Vector3D p0(mesh->positions[v1]), p1(mesh->positions[v2]), p2(mesh->positions[v3]);
    Vector3D E1 = p1 - p0;
    Vector3D E2 = p2 - p0;
    Vector3D S = r.o - p0;
    Vector3D S1 = cross(r.d, E2);
    Vector3D S2 = cross(S, E1);
    
    Vector3D results = (1.0 / dot(S1, E1)) * Vector3D(dot(S2, E2), dot(S1, S), dot(S2, r.d));
    double t = results[0];
    if (t > r.max_t or t < r.min_t) {
        return false;
    }
    else {
        r.max_t = t;
        return true;
    }

  return false;


}

bool Triangle::intersect(const Ray& r, Intersection *isect) const {
  
  // TODO (Part 1.3):
  // implement ray-triangle intersection. When an intersection takes
  // place, the Intersection data should be updated accordingly

  Vector3D p0(mesh->positions[v1]), p1(mesh->positions[v2]), p2(mesh->positions[v3]);
  Vector3D n1(mesh->normals[v1]), n2(mesh->normals[v2]), n3(mesh->normals[v3]);
//    std::cout<< "p0: "<< p0 << endl;
//    std::cout<< "p1: "<< p1 << endl;
//    std::cout<< "p2: "<< p2 << endl;
    
    Vector3D E1 = p1 - p0;
    Vector3D E2 = p2 - p0;
    Vector3D S = r.o - p0;
    Vector3D S1 = cross(r.d, E2);
    Vector3D S2 = cross(S, E1);
//    std::cout<< "e1: "<< E1 << endl;
//    std::cout<< "s: "<< S << endl;
//    std::cout<< "s2: "<< S2 << endl;
//    std::cout<< "dir: "<< r.d.norm() << endl;
    
    
    Vector3D results = (1.0 / dot(S1, E1)) * Vector3D(dot(S2, E2), dot(S1, S), dot(S2, r.d));
    double t = results[0];
    double b1 = results[1];
    double b2 = results[2];
//    std::cout<< "t: " << t << endl;
//    std::cout<<"max: " << r.max_t << endl;
//    std::cout<<"min: " << r.min_t << endl;
//    std::cout<<"b1: " << b1 << endl;
//    std::cout<<"b2: " << b2 << endl;
//
    
    //std::cout<< t << endl;
    
    if (t > r.max_t or t < r.min_t or
        b1 > 1 or b1 < 0 or b2 >1 or b2 < 0 or (1-b1-b2)>1 or (1-b1-b2)<0) {
        //isect->bsdf = get_bsdf();

        return false;
    }

    //std::cout<< "found intersection" << endl;
    isect->t = t;
    isect->primitive = this;
    isect->bsdf = get_bsdf();
    isect->n = (1-b1-b2) * n1 + b1 * n2 + b2 * n3;
    r.max_t = t;
    return true;
    
  
}

void Triangle::draw(const Color& c, float alpha) const {
  glColor4f(c.r, c.g, c.b, alpha);
  glBegin(GL_TRIANGLES);
  glVertex3d(mesh->positions[v1].x,
             mesh->positions[v1].y,
             mesh->positions[v1].z);
  glVertex3d(mesh->positions[v2].x,
             mesh->positions[v2].y,
             mesh->positions[v2].z);
  glVertex3d(mesh->positions[v3].x,
             mesh->positions[v3].y,
             mesh->positions[v3].z);
  glEnd();
}

void Triangle::drawOutline(const Color& c, float alpha) const {
  glColor4f(c.r, c.g, c.b, alpha);
  glBegin(GL_LINE_LOOP);
  glVertex3d(mesh->positions[v1].x,
             mesh->positions[v1].y,
             mesh->positions[v1].z);
  glVertex3d(mesh->positions[v2].x,
             mesh->positions[v2].y,
             mesh->positions[v2].z);
  glVertex3d(mesh->positions[v3].x,
             mesh->positions[v3].y,
             mesh->positions[v3].z);
  glEnd();
}



} // namespace StaticScene
} // namespace CGL
