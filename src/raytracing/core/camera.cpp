#include <raytracing/core/camera.h>

Camera::Camera(
    Point3 lookfrom_, Point3 lookat_, Vector3 up_,
    double fov_, double aspect_ratio_, double aperture_,
    double focus_dist_
)
    : lookfrom(lookfrom_), lookat(lookat_), up(up_)
    , fov(fov_), aspect_ratio(aspect_ratio_)
    , aperture(aperture_), focus_dist(focus_dist_)
{
    auto theta = Radians(fov);
    viewport_h = 2.0 * focus_dist *  tan(theta / 2);
    viewport_w = aspect_ratio * viewport_h;

    w = Normalize(lookat - lookfrom);
    u = Normalize(Cross(w, up));
    v = Cross(u, w);

    horizontal = viewport_w * u;
    vertical = viewport_h * v;
    lower_left_corner = lookfrom - horizontal / 2 - vertical / 2 + focus_dist * w;

    lens_radius = aperture_ / 2;
}

Ray Camera::GenerateRay(double u, double v) const {
    // Vector3 rd = lens_radius * RandomInUnitDisk();
    // Vector3 offset = u * rd.x + v * rd.y;

    return Ray(
                lookfrom,
                lower_left_corner + u * horizontal + v * vertical - lookfrom
           );
}

Camera Camera::basic_camera() {
    Point3 lookfrom(0.0f, 0.0f, 0.0f);
    Point3 lookat(0.0f, 0.0f, -1.0f);
    Vector3 vup(0.0f, 1.0f, 0.0f);
    double aspect_ratio = 16.0 / 9.0;// 比例必须和 image 一样
    auto dist_to_focus = 1.0;
    auto aperture = 0.1;
    Camera cam(lookfrom, lookat, vup, 90, aspect_ratio, aperture, dist_to_focus);

    return cam;
}

