#include <raytracing/core/primitive.h>

GeometryPrimitive::GeometryPrimitive(std::shared_ptr<Shape> shape)
    : shape(shape)
{}

bool GeometryPrimitive::Intersect(const Ray& ray_, Interaction& record_) const
{
    if(!shape->Intersect(ray_, record_)) {
        return false;
    }
    
    return true;
}