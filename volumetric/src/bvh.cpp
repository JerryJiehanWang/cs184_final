#include "bvh.h"

#include "CGL/CGL.h"
#include "static_scene/triangle.h"

#include <iostream>
#include <stack>

using namespace std;

namespace CGL { namespace StaticScene {

BVHAccel::BVHAccel(const std::vector<Primitive *> &_primitives,
                   size_t max_leaf_size) {

  root = construct_bvh(_primitives, max_leaf_size);

}

BVHAccel::~BVHAccel() {
  if (root) delete root;
}

BBox BVHAccel::get_bbox() const {
  return root->bb;
}

void BVHAccel::draw(BVHNode *node, const Color& c, float alpha) const {
  if (node->isLeaf()) {
    for (Primitive *p : *(node->prims))
      p->draw(c, alpha);
  } else {
    draw(node->l, c, alpha);
    draw(node->r, c, alpha);
  }
}

void BVHAccel::drawOutline(BVHNode *node, const Color& c, float alpha) const {
  if (node->isLeaf()) {
    for (Primitive *p : *(node->prims))
      p->drawOutline(c, alpha);
  } else {
    drawOutline(node->l, c, alpha);
    drawOutline(node->r, c, alpha);
  }
}

BVHNode *BVHAccel::construct_bvh(const std::vector<Primitive*>& prims, size_t max_leaf_size) {
  
  // TODO (Part 2.1):
  // Construct a BVH from the given vector of primitives and maximum leaf
  // size configuration. The starter code build a BVH aggregate with a
  // single leaf node (which is also the root) that encloses all the
  // primitives.
    
    BBox centroid_box, bbox;
    
    for (Primitive *p : prims) {
        BBox bb = p->get_bbox();
        bbox.expand(bb);
        Vector3D c = bb.centroid();
        centroid_box.expand(c);
    }
    BVHNode *node = new BVHNode(bbox);
    if (prims.size() <= max_leaf_size) {
        node->prims = new std::vector<Primitive *>(prims);
        return node;
    }
    else {
        double extents[] = {bbox.extent[0], bbox.extent[1],bbox.extent[2]};
        const int N = sizeof(bbox) / sizeof(double);
        int dim = std::distance(extents, max_element(extents, extents+N));
        //std::cout<<"dim :" <<dim<<endl;
        Vector3D split = centroid_box.centroid();
        
        std::vector<Primitive*> left = std::vector<Primitive*>();
        std::vector<Primitive*> right = std::vector<Primitive*>();
        
        for (int i = 0; i < prims.size(); i++) {
            Primitive *p = prims[i];
            if (p->get_bbox().centroid()[dim] < split[dim]) {
                left.push_back(p);
            }
            else{
                right.push_back(p);
            }
        }
        if (left.size() == 0) {
            std::cout<<"left empty"<<endl;
            std::vector<Primitive*> new_right = std::vector<Primitive*>();
            for (int i = 0; i < right.size(); i++) {
                Primitive *p = prims[i];
                if (rand() % 10 > 5) {
                    left.push_back(p);
                }
                else{
                    new_right.push_back(p);
                }
            }
            right = new_right;
//            double new_split = 0.0;
//
//            std::vector<double> cents = std::vector<double>(right.size());
//            for (Primitive *p : right) {
//                cents.push_back(p->get_bbox().centroid()[dim]);
//            }
//            int n = sizeof(cents)/sizeof(double);
//
//            std::sort(cents.begin(), cents.begin()+n);
//            new_split = cents[(int) cents[right.size()/2]];
//            std::vector<Primitive*> new_right = std::vector<Primitive*>();
//            for (int i = 0; i < right.size(); i++) {
//                if (right[i]->get_bbox().centroid()[dim] < new_split) {
//                    left.push_back(right[i]);
//                }
//                else {
//                    new_right.push_back(right[i]);
//                }
//            }
//            right = new_right;
            
        }
        if (right.size() == 0) {
            std::cout<<"right empty"<<endl;
            std::vector<Primitive*> new_left = std::vector<Primitive*>();
            for (int i = 0; i < left.size(); i++) {
                Primitive *p = prims[i];
                if (rand() % 10 > 5) {
                    right.push_back(p);
                }
                else{
                    new_left.push_back(p);
                }
            }
            left = new_left;
//            double new_split = 0.0;
//
//            std::vector<double> cents = std::vector<double>(left.size());
//            for (Primitive *p : left) {
//                cents.push_back(p->get_bbox().centroid()[dim]);
//            }
//            int n = sizeof(cents)/sizeof(double);
//
//            std::sort(cents.begin(), cents.begin()+n);
//            new_split = cents[(int) cents[left.size()/2]];
//            std::vector<Primitive*> new_left = std::vector<Primitive*>();
//            for (int i = 0; i < left.size(); i++) {
//                if (left[i]->get_bbox().centroid()[dim] < new_split) {
//                    right.push_back(right[i]);
//                }
//                else {
//                    new_left.push_back(right[i]);
//                }
//            }
//            left = new_left;
            
            
        }
        //std::cout<< left.size() << " " << right.size()<< endl;
        node->prims = NULL;
        node->l = construct_bvh(left, max_leaf_size);
        node->r = construct_bvh(right, max_leaf_size);
        
        
        
        return node;
        
    }
    }
  






bool BVHAccel::intersect(const Ray& ray, BVHNode *node) const {

  // TODO (Part 2.3):
  // Fill in the intersect function.
  // Take note that this function has a short-circuit that the
  // Intersection version cannot, since it returns as soon as it finds
  // a hit, it doesn't actually have to find the closest hit.
    
    if (node->prims == NULL) {
        return intersect(ray, node->l) || intersect(ray, node->r);
    }
    else {
        for (Primitive *p : *(node->prims)) {
            total_isects++;
            if (p->intersect(ray)){
                return true;
            }
        }
        return false;
            
        
    }

    
}

bool BVHAccel::intersect(const Ray& ray, Intersection* i, BVHNode *node) const {

  // TODO (Part 2.3):
  // Fill in the intersect function.


  bool hit = false;
    double bb1, bb2;
    bool inter = node->bb.intersect(ray, bb1, bb2);
    
    
    if (not inter){
            //i->t = INFINITY;
        //std::cout<<"bb1: " << bb1 << " bb2: " << bb2 <<endl;
        //std::cout<<"no intersect "<< std::endl;
            return false;
    }
    
    else if (node->prims != NULL) {

        for (Primitive *p : *(node->prims)) {
            total_isects++;
            if (p->intersect(ray, i)) {
                hit = true;
                
            }
            
        }
    }
    else {

        bool lefti = intersect(ray, i, node->l);
        bool righti = intersect(ray, i, node->r);
        hit = lefti or righti;
    }
  
  return hit;

  
}

}  // namespace StaticScene
}  // namespace CGL
