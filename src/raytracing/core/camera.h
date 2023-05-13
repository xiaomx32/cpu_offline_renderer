#ifndef CAMERA_H_
#define CAMERA_H_

#include <basic/ray/ray.h>

class Image;

class Camera {
public:
    Point3 lookfrom { 0.0f, 0.0f, 0.0f };
    Point3 lookat { 0.0f, 0.0f, -1.0f };
    Vector3 up { 0.0f, 1.0f, 0.0f };

    Point3 lower_left_corner;
    float viewport_w;
    float viewport_h;
    Vector3 horizontal;
    Vector3 vertical;

    Vector3 u, v, w;
    double fov { 90.0 };// vertical field-of-view in degrees
    double aspect_ratio { 16.0 / 9.0 };
    double aperture { 0.1 };
    double focus_dist { 1.0 };
    double lens_radius { 1.0 };

public:
    Camera(
        Point3 lookfrom_ = { 0.0f, 0.0f, 0.0f },
        Point3 lookat_ = { 0.0f, 0.0f, -1.0f },
        Vector3 up_ = { 0.0f, 1.0f, 0.0f },
        double fov_ = { 90.0 }, double aspect_ratio_ = { 16.0 / 9.0 }, double aperture_ = { 0.1 },
        double focus_dist_ = { 1.0 }
    );

    Ray GenerateRay(double u, double v) const;

    static Camera basic_camera();
    
};

#endif // CAMERA_H_

