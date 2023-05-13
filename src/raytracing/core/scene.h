#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <raytracing/core/primitive.h>
#include <raytracing/shapes/sphere.h>

class Scene {
public:
    std::vector<std::shared_ptr<GeometryPrimitive>> primitives;
    //transform_vector transforms;

public:
    Scene() = default;
    Scene(
        std::vector<std::shared_ptr<GeometryPrimitive>> primitives
    );

    Scene& Add(std::shared_ptr<GeometryPrimitive> primitive);
    //std::optional<Interaction> intersect(const Ray& ray) const;
    bool Intersect(const Ray& r, Interaction& record_) const;

    static Scene MakeScene_Hello();

};
#endif // SCENE_H_