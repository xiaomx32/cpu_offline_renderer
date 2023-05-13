#ifndef SHAPE_H_
#define SHAPE_H_

#include <raytracing/core/transform.h>
#include <raytracing/core/interaction.h>

class Shape {
public:
    const Matrix4x4 ObjectToWorld;// 不用左值引用，避免函数返回后出现悬垂引用
    const Matrix4x4 WorldToObject;

public:
    Shape(const Matrix4x4& ObjectToWorld_, const Matrix4x4& WorldToObject_);
    virtual ~Shape() = default;
    
    virtual bool Intersect(const Ray& ray_) const = 0;// fast test
    virtual bool Intersect(const Ray& ray_, Interaction& record) const = 0;

};
#endif //SHAPE_H_