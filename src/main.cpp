#include <raytracing/core/image.h>
#include <raytracing/core/camera.h>
#include <raytracing/core/scene.h>
#include <raytracing/core/color.h>
#include <iostream>

Color ray_color(const Ray& r, Scene& world);

int main() {
    // image
    Image image = Image::basic_image();

    // Camera
    Camera camera = Camera::basic_camera();

    // World
    Scene world = Scene::MakeScene_Hello();

    // Render
    std::cout << "P3\n" << image.width << " " << image.height << "\n255\n";
    for (int j = image.height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image.width; ++i) {
            auto u = double(i) / (double)(image.width - 1);
            auto v = double(j) / (double)(image.height - 1);
            Ray r = camera.GenerateRay(u, v);
            Color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}

Color ray_color(const Ray& r, Scene& world) {
    Interaction rec;
    if (world.Intersect(r, rec)) {
        return rec.normal;
        // return { 0.0f, 0.0f, 0.0f };
        // return { 255.0f, 255.0f, 255.0f };
    }

    Vector3 unit_direction = Normalize(r.direction);
    auto t = 0.5 * (unit_direction.y + 1.0);

    return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}