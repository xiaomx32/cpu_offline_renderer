#include <raytracing/shapes/sphere.h>

Sphere::Sphere(
		const Matrix4x4& ObjectToWorld_,
        const Matrix4x4& WorldToObject_,
		float r_
)
    : Shape(ObjectToWorld_, WorldToObject_)
    , radius(r_)
{}

bool Sphere::Intersect(const Ray& ray_) const{
    const auto ray = WorldToObject * ray_;
    const auto oc = ray.origin - Point3 { 0.0f, 0.0f, 0.0f };

    const auto a = ray.direction.LengthSquared();
    const auto half_b = Dot(oc, ray.direction);
    const auto c = oc.LengthSquared() - radius * radius;
    
    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0) { return false; }

    return true;
}

bool Sphere::Intersect(const Ray& ray_, Interaction& record_) const {
    const auto ray = WorldToObject * ray_;
    const auto oc = ray.origin - Point3{ 0.0f, 0.0f, 0.0f };

    const auto a = ray.direction.LengthSquared();
    const auto half_b = Dot(oc, ray.direction);
    const auto c = oc.LengthSquared() - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant > 0) {
        auto sqrtd = std::sqrt(discriminant);
        float t = (- half_b - sqrtd) / a;
        if(t < record_.t_min || t <= 0.001f || t >= record_.t_max) { return false; }
        record_.t_min = t;
        record_.p = ray.At(record_.t_min);
        record_.normal = (record_.p - Point3 {0.0f, 0.0f, 0.0f }) / radius;

        return true;
    }

    return false;
}
