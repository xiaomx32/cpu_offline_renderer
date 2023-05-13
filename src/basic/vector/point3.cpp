#include <basic/vector/point3.h>

// Point3 constructor
Point3::Point3(float v)
    : x(v), y(v), z(v)
{}

Point3::Point3(float xx, float yy, float zz)
    : x(xx), y(yy), z(zz)
{}


Point3::Point3(const Point3& p)
    : x(p.x), y(p.y), z(p.z)
{}


// Point3 Public Methods
Point3& Point3::operator=(const Point3& p) {
    x = p.x;
    y = p.y;
    z = p.z;

    return *this;
}

Point3 Point3::operator+(const Vector3& v) const {
    return Point3(x + v.x, y + v.y, z + v.z);
}

Point3& Point3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vector3 Point3::operator-(const Point3& p) const {
    return Vector3(x - p.x, y - p.y, z - p.z);
}

Point3 Point3::operator-(const Vector3& v) const {
    return Point3(x - v.x, y - v.y, z - v.z);
}

Point3& Point3::operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Point3& Point3::operator+=(const Point3& p) {
    x += p.x;
    y += p.y;
    z += p.z;
    return *this;
}

Point3 Point3::operator+(const Point3& p) const {
    return Point3(x + p.x, y + p.y, z + p.z);
}

Point3 Point3::operator*(float f) const {
    return Point3(f * x, f * y, f * z);
}

Point3& Point3::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

Point3 Point3::operator/(float f) const {
    float inv = (float)1 / f;
    return Point3(inv * x, inv * y, inv * z);
}

Point3& Point3::operator/=(float f) {
    float inv = (float)1 / f;
    x *= inv;
    y *= inv;
    z *= inv;
    return *this;
}

float Point3::operator[](int i) const {
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
}

float& Point3::operator[](int i) {
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
}

bool Point3::operator==(const Point3& p) const {
    return x == p.x && y == p.y && z == p.z;
}

bool Point3::operator!=(const Point3& p) const {
    return x != p.x || y != p.y || z != p.z;
}

Point3 Point3::operator-() const { return Point3(-x, -y, -z); }




/////
Point3 Abs(const Point3& p) {
    return Point3(std::abs(p.x), std::abs(p.y), std::abs(p.z));
}

float Distance(const Point3& p1, const Point3& p2) {
    return (p1 - p2).Length();
}

float DistanceSquared(const Point3& p1, const Point3& p2) {
    return (p1 - p2).LengthSquared();
}

Point3 Lerp(float t, const Point3& p0, const Point3& p1) {
    return (1 - t) * p0 + t * p1;
}

Point3 operator*(float f, const Point3& p) {
    return p * f;
}