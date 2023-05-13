#include <basic/vector/vector2.h>

// Vector2 constructor
Vector2::Vector2(float v)
    : x(v), y(v)
{}

Vector2::Vector2(float xx, float yy)
    : x(xx), y(yy)
{}

Vector2::Vector2(const Vector2& v)
    : x(v.x), y(v.y)
{}



// Vector2 Public Methods
Vector2& Vector2::operator=(const Vector2& v) {
    x = v.x;
    y = v.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
}

Vector2& Vector2::operator+=(const Vector2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2& v) const {
    return Vector2(x - v.x, y - v.y);
}

Vector2& Vector2::operator-=(const Vector2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

bool Vector2::operator==(const Vector2& v) const {
    return x == v.x && y == v.y;
}


bool Vector2::operator!=(const Vector2& v) const {
    return x != v.x || y != v.y;
}

Vector2 Vector2::operator*(float f) const {
    return Vector2(f * x, f * y);
}

Vector2& Vector2::operator*=(float f) {
    x *= f;
    y *= f;
    return *this;
}

Vector2 Vector2::operator/(float f) const {
    float inv = (float)1 / f;
    return Vector2(x * inv, y * inv);
}

Vector2& Vector2::operator/=(float f) {
    float inv = (float)1 / f;
    x *= inv;
    y *= inv;
    return *this;
}

Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

float Vector2::operator[](int i) const {
    if (i == 0) return x;
    return y;
}

float& Vector2::operator[](int i) {
    if (i == 0) return x;
    return y;
}

float Vector2::LengthSquared() const {
    return x * x + y * y;
}

float Vector2::Length() const {
    return std::sqrt(LengthSquared());
}




////
Vector2 Abs(const Vector2& v) {
    return Vector2(std::abs(v.x), std::abs(v.y));
}

inline float AbsDot(const Vector2& v1, const Vector2& v2) {
    return std::abs(Dot(v1, v2));
}

inline float Dot(const Vector2& v1, const Vector2& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

inline Vector2 Normalize(const Vector2& v) {
    return v / v.Length();
}

inline Vector2 operator*(float f, const Vector2& v) {
    return v * f;
}