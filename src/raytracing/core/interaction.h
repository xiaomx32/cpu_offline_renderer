#ifndef INTERACTION_H_
#define INTERACTION_H_

#include <basic/ray/ray.h>

class Interaction {
public:
    float t_min = 0.0f;
    float t_max = Infinity;
    Point3 p;
    Normal3 normal;
    //std::shared_ptr<material> material_ptr;
    bool front_face;

public:
    Interaction() = default;
    inline void set_face_normal(const Ray& r, const Vector3& outward_normal) {
        front_face = Dot(r.direction, outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};
#endif // INTERACTION_H_