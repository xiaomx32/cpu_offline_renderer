#ifndef RAY_H_
#define RAY_H_

#include <basic/vector/point3.h>

class Ray {
public:
    Point3 origin;
    Vector3 direction;

public:
    Ray() = default;
    Ray(const Point3& ori_, const Vector3& dir_);

    Point3 At(double t) const;
};
#endif
