#ifndef POINT3_H_
#define POINT3_H_

#include <basic/vector/vector3.h>

class Point3 {
public:
	// Point3 public data
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };

public:
	// Point3 constructor
	Point3() = default;
	Point3(float v);
	Point3(float xx, float yy, float zz);
	Point3(const Point3& p);

	// Point3 Public Methods
	Point3& operator=(const Point3& p);
	Point3 operator+(const Vector3& v) const;
	Point3& operator+=(const Vector3& v);
	Vector3 operator-(const Point3& p) const;
	Point3 operator-(const Vector3& v) const;
	Point3& operator-=(const Vector3& v);
	Point3& operator+=(const Point3& p);
	Point3 operator+(const Point3& p) const;

	Point3 operator*(float f) const;
	Point3& operator*=(float f);
	Point3 operator/(float f) const;
	Point3& operator/=(float f);

	float operator[](int i) const;
	float& operator[](int i);
	bool operator==(const Point3& p) const;
	bool operator!=(const Point3& p) const;
	Point3 operator-() const;
};

Point3 Abs(const Point3& p);

float Distance(const Point3& p1, const Point3& p2);

float DistanceSquared(const Point3& p1, const Point3& p2);

Point3 Lerp(float t, const Point3& p0, const Point3& p1);

Point3 operator*(float f, const Point3& p);
#endif // POINT3_H_