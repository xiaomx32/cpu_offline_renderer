#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <basic/util/mathtool.h>

class Vector3 {
public:
	// Vector3 public data
	float x{ 0.0f };
	float y{ 0.0f };
	float z{ 0.0f };

public:
	// Vector3 constructor
	Vector3() = default;
	Vector3(float v);
	Vector3(float xx, float yy, float zz);
	Vector3(const Vector3& v);

	// Vector3 public methods
	Vector3& operator=(const Vector3& v);
	Vector3 operator+(const Vector3& v) const;
	Vector3& operator+=(const Vector3& v);
	Vector3 operator-(const Vector3& v) const;
	Vector3& operator-=(const Vector3& v);
	bool operator==(const Vector3& v) const;
	bool operator!=(const Vector3& v) const;

	Vector3 operator*(float s) const;
	Vector3& operator*=(float s);
	Vector3 operator/(float f) const;
	Vector3& operator/=(float f);

	Vector3 operator-() const;
	float operator[](int i) const;
	float& operator[](int i);
	float LengthSquared() const;
	float Length() const;
};

using Normal3 = Vector3;
using Color = Vector3;
using Spectrum = Vector3;

inline Vector3 operator*(double t, const Vector3& v) {
	return Vector3(t * v.x, t * v.y, t * v.z);
}

inline Vector3 operator*(const Vector3& u, const Vector3& v) {
	return Vector3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vector3 Normalize(const Vector3& v) {
	return v / v.Length();
}

inline Vector3 Abs(const Vector3& v) {
	return Vector3{ std::abs(v.x), std::abs(v.y), std::abs(v.z) };
}

inline float Dot(const Vector3& v1, const Vector3& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	double v1x = v1.x, v1y = v1.y, v1z = v1.z;
	double v2x = v2.x, v2y = v2.y, v2z = v2.z;

	return Vector3(
				(v1y * v2z) - (v1z * v2y),
				(v1z * v2x) - (v1x * v2z),
				(v1x * v2y) - (v1y * v2x)
			);
}

inline Vector3 RandomInUnitDisk() {// 返回 -1 到 1 单位圆面上的二维随机点
    while (true) {
        auto p = Vector3(RandomDouble(-1, 1), RandomDouble(-1,1), 0);
        if (p.LengthSquared() >= 1) continue;
        return p;
    }
}

inline Vector3 Faceforward(const Vector3& v, const Vector3& v2) {
	return (Dot(v, v2) < 0.f) ? -v : v;
}

inline Vector3 reflect(const Vector3& v, const Vector3& n) {
	return v - 2 * Dot(v, n) * n;
}

inline Vector3 refract(const Vector3& uv, const Vector3& n, double etai_over_etat) {
	auto cos_theta = fmin(Dot(-uv, n), 1.0);
	Vector3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
	Vector3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.LengthSquared())) * n;
	return r_out_perp + r_out_parallel;
}

#endif // VECTOR3_H_
