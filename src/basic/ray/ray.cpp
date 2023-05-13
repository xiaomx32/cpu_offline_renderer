#include <basic/ray/ray.h>

Ray::Ray(const Point3& ori_, const Vector3& dir_)
    : origin(ori_)
    , direction(dir_)
{}

Point3 Ray::At(double t) const { return origin + t * direction; }
