#ifndef POINT2_H_
#define POINT2_H_

#include <basic/vector/vector2.h>

class Point2 {
public:
    // Point2 public data
    float x;
    float y;

public:
    // Point2 constructor
    Point2() = default;
    Point2(float v);
    Point2(float xx, float yy);
    Point2(const Point2& p);
    //explicit Point2(const Point3& p);

    // Point2 Public Methods
    Point2& operator=(const Point2& p);
    Point2 operator+(const Vector2& v) const;
    Point2& operator+=(const Vector2& v);
    Vector2 operator-(const Point2& p) const;
    Point2 operator-(const Vector2& v) const;
    Point2& operator-=(const Vector2& v);
    Point2& operator+=(const Point2& p);
    Point2 operator+(const Point2& p) const;
    bool operator==(const Point2& p) const;
    bool operator!=(const Point2& p) const;

    Point2 operator*(float f) const;
    Point2& operator*=(float f);
    Point2 operator/(float f) const;
    Point2& operator/=(float f);

    Point2 operator-() const;
    float operator[](int i) const;
    float& operator[](int i);
};

inline float Distance(const Point2& p1, const Point2& p2);

inline float DistanceSquared(const Point2& p1, const Point2& p2);

Point2 Lerp(float t, const Point2& v0, const Point2& v1);

inline Point2 operator*(float f, const Point2& p);
#endif // POINT2_H_