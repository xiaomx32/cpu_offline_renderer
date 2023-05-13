#include <raytracing/core/shape.h>

Shape::Shape(const Matrix4x4& ObjectToWorld_, const Matrix4x4& WorldToObject_)
    : ObjectToWorld(ObjectToWorld_)
    , WorldToObject(WorldToObject_)
{}