#ifndef SPHERE_H
#define SPHERE_H

#include <raytracing/core/shape.h>
#include <basic/vector/vector3.h>

class Sphere : public Shape {
public:
	float radius { 1.0f };

public:
	Sphere(
		const Matrix4x4& ObjectToWorld_,
		const Matrix4x4& WorldToObject,
		float r_
	);

    virtual bool Intersect(const Ray& ray_) const override;
	virtual bool Intersect(const Ray& ray_, Interaction& record_) const override;

};

#endif // SPHERE_H_
