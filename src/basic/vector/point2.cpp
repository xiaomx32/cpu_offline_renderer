#include <basic/vector/point2.h>

// Point2 constructor

Point2::Point2(float v)
    : x(v), y(v)
{}

Point2::Point2(float xx, float yy)
    : x(xx), y(yy)
{}

Point2::Point2(const Point2& p)
    : x(p.x), y(p.y)
{}


// Point2 Public Methods
Point2& Point2::operator=(const Point2& p) {
    x = p.x;
    y = p.y;
    return *this;
}

Point2 Point2::operator+(const Vector2& v) const {
    return Point2(x + v.x, y + v.y);
}

Point2& Point2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vector2 Point2::operator-(const Point2& p) const {
    return Vector2(x - p.x, y - p.y);
}

Point2 Point2::operator-(const Vector2& v) const {
    return Point2(x - v.x, y - v.y);
}

Point2& Point2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Point2& Point2::operator+=(const Point2& p) {
    x += p.x;
    y += p.y;
    return *this;
}

Point2 Point2::operator+(const Point2& p) const {
    return Point2(x + p.x, y + p.y);
}

Point2 Point2::operator-() const {
    return Point2(-x, -y);
}

float Point2::operator[](int i) const {
    if (i == 0) return x;
    return y;
}

float& Point2::operator[](int i) {
    if (i == 0) return x;
    return y;
}

bool Point2::operator==(const Point2& p) const {
    return x == p.x && y == p.y;
}

bool Point2::operator!=(const Point2& p) const {
    return x != p.x || y != p.y;
}

Point2 Point2::operator*(float f) const {
    return Point2(f * x, f * y);
}

Point2& Point2::operator*=(float f) {
    x *= f;
    y *= f;
    return *this;
}

Point2 Point2::operator/(float f) const {
    float inv = (float)1 / f;
    return Point2(inv * x, inv * y);
}

Point2& Point2::operator/=(float f) {
    float inv = (float)1 / f;
    x *= inv;
    y *= inv;
    return *this;
}


////
inline float Distance(const Point2& p1, const Point2& p2) {
    return (p1 - p2).Length();
}

inline float DistanceSquared(const Point2& p1, const Point2& p2) {
    return (p1 - p2).LengthSquared();
}

Point2 Lerp(float t, const Point2& v0, const Point2& v1) {
    return (1 - t) * v0 + t * v1;
}

inline Point2 operator*(float f, const Point2& p) {
    return p * f;
}