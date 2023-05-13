#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <basic/vector/vector3.h>

class Vector2 {
public:
	// Vector2 public data
	float x{ 0.0f };
	float y{ 0.0f };

public:
	// Vector2 constructor
	Vector2() = default;
	Vector2(float v);
	Vector2(float xx, float yy);
	Vector2(const Vector2& v);

	// Vector2 public methods
	Vector2& operator=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	Vector2& operator+=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;
	Vector2& operator-=(const Vector2& v);
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;

	Vector2 operator*(float f) const;
	Vector2& operator*=(float f);
	Vector2 operator/(float f) const;
	Vector2& operator/=(float f);

	Vector2 operator-() const;
	float operator[](int i) const;
	float& operator[](int i);
	float LengthSquared() const;
	float Length() const;
};

Vector2 Abs(const Vector2& v);

inline float AbsDot(const Vector2& v1, const Vector2& v2);

inline float Dot(const Vector2& v1, const Vector2& v2);

inline Vector2 Normalize(const Vector2& v);

inline Vector2 operator*(float f, const Vector2& v);

#endif // VECTOR2_H_
