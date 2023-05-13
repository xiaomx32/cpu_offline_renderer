#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include <memory>
#include <raytracing/core/shape.h>

class Primitive {
public:
    virtual ~Primitive() = default;

    virtual bool Intersect(const Ray& ray_, Interaction& record) const = 0;
};




class GeometryPrimitive : public Primitive {
public:
    const std::shared_ptr<Shape> shape;
    //std::shared_ptr<Material> material;
    //std::shared_ptr<Light> light;

public:
    GeometryPrimitive() = default;
    GeometryPrimitive(std::shared_ptr<Shape> shape_);

    virtual bool Intersect(const Ray& ray_, Interaction& record_) const override;

};
#endif // PRIMITIVE_H_