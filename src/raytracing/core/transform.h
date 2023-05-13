#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <cstring>
#include <iostream>
#include <basic/ray/ray.h>

// most uses of transformations in here are for transforming points from one frame to another
// transformations make it possible to work in the most convenient coordinate space

struct Matrix4x4 {
public:
	// Matrix4x4 public data
	float m[4][4];

public:
	// Matrix4x4 constructor
	Matrix4x4();
	Matrix4x4(float mat[4][4]);
	Matrix4x4(
		float t00, float t01, float t02, float t03,
		float t10, float t11, float t12, float t13,
		float t20, float t21, float t22, float t23,
		float t30, float t31, float t32, float t33
	);

	// Matrix4x4 Public Methods
	bool operator==(const Matrix4x4& m2) const;
	bool operator!=(const Matrix4x4& m2) const;

	static Matrix4x4 Mul(const Matrix4x4& m1, const Matrix4x4& m2);
	friend Matrix4x4 Transpose(const Matrix4x4& m);
	friend Matrix4x4 Inverse(const Matrix4x4& m);
};
Vector3 operator*(const Matrix4x4& lhs, const Vector3& rhs);
Point3 operator*(const Matrix4x4& lhs, const Point3& rhs);
Ray operator*(const Matrix4x4& lhs, const Ray& rhs);

class Transform {
public:
	// Transform Private Data
	Matrix4x4 m;
	Matrix4x4 mInv;// inverse of the m

public:
	// Transform constructor
	Transform();
	Transform(const float mat[4][4]);
	Transform(const Matrix4x4& m);
	Transform(const Matrix4x4& m, const Matrix4x4& mInv);

	// Transform Public Methods
	const Matrix4x4& GetMatrix() const;
	const Matrix4x4& GetInverseMatrix() const;

	friend Transform Inverse(const Transform& t);
	friend Transform Transpose(const Transform& t);
	bool operator==(const Transform& t) const;
	bool operator!=(const Transform& t) const;
	bool operator<(const Transform& t2) const;
	bool IsIdentity() const;

	Point3 operator()(const Point3& p) const;
	Vector3 operator()(const Vector3& v) const;
	Ray operator()(const Ray& r) const;
	Transform operator*(const Transform& t2) const;
};

// translation only affects points, leaving vectors unchanged
Transform Translate(const Vector3& delta);
Transform Scale(float x, float y, float z);
Transform RotateX(float theta);
Transform RotateY(float theta);
Transform RotateZ(float theta);
Transform Rotate(float theta, const Vector3& axis);
Transform LookAt(const Point3& pos, const Point3& look, const Vector3& up);
Transform Orthographic(float znear, float zfar);
Transform Perspective(float fov, float znear, float zfar);

#endif