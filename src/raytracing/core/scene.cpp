#include <raytracing/core/scene.h>

Scene::Scene(
    std::vector<std::shared_ptr<GeometryPrimitive>> primitives_
)
    :primitives(primitives_)
{}

Scene& Scene::Add(std::shared_ptr<GeometryPrimitive> primitive)
{
    primitives.push_back(primitive);
    return *this;
}

bool Scene::Intersect(const Ray& r, Interaction& record_) const {
    for (const auto& primitive : primitives) {
        bool hit_anything = false;
        if (primitive->Intersect(r, record_)) {
            hit_anything = true;
            return hit_anything;
        }
    }

    return false;
}

Scene Scene::MakeScene_Hello() {
    const Matrix4x4 ObjectToWorld_1 {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, -1.0f,
            0.0f, 0.0f, 0.0f, 1.0f
    };
    Matrix4x4 WorldToObject_1 = Inverse(ObjectToWorld_1);

    const Matrix4x4 ObjectToWorld_2 {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, -100.5f,
            0.0f, 0.0f, 1.0f, -1.0f,
            0.0f, 0.0f, 0.0f, 1.0f
    };
    Matrix4x4 WorldToObject_2 = Inverse(ObjectToWorld_2);

    Scene world;
    world.Add(std::make_shared<GeometryPrimitive>(
            std::make_shared<Sphere>(ObjectToWorld_1, WorldToObject_1, 0.5)
        )
    );
    world.Add(std::make_shared<GeometryPrimitive>(
        std::make_shared<Sphere>(ObjectToWorld_2, WorldToObject_2, 100)
        )
    );

    return world;
}