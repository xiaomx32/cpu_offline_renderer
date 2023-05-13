#include <basic/vector/vector3.h>

// Vector3 constructor
Vector3::Vector3(float v) : x(v), y(v), z(v) {}

Vector3::Vector3(float xx, float yy, float zz)
	: x(xx), y(yy), z(zz)
{}

Vector3::Vector3(const Vector3& v)
	: x(v.x), y(v.y), z(v.z)
{}


// Vector3 public methods
Vector3& Vector3::operator=(const Vector3& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3& v) const {
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3& Vector3::operator+=(const Vector3& v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;

	return *this;
}

Vector3 Vector3::operator-(const Vector3& v) const {
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3& Vector3::operator-=(const Vector3& v) {
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;

	return *this;
}

bool Vector3::operator==(const Vector3& v) const {
	return x == v.x && y == v.y && z == v.z;
}

bool Vector3::operator!=(const Vector3& v) const {
	return x != v.x || y != v.y || z != v.z;
}




Vector3 Vector3::operator*(float s) const {
	return Vector3(s * x, s * y, s * z);
}

Vector3& Vector3::operator*=(float s) {
	this->x *= s;
	this->y *= s;
	this->z *= s;

	return *this;
}

Vector3 Vector3::operator/(float f) const {
	float inv = static_cast<float>(1 / f);
	return Vector3(x * inv, y * inv, z * inv);
}

Vector3& Vector3::operator/=(float f) {
	float inv = static_cast<float>(1 / f);
	x *= inv;
	y *= inv;
	z *= inv;

	return *this;
}




Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

float Vector3::operator[](int i) const {
	if (i == 0) { return x; }
	if (i == 1) { return y; }

	return z;
}

float& Vector3::operator[](int i) {
	if (i == 0) { return x; }
	if (i == 1) { return y; }

	return z;
}

float Vector3::LengthSquared() const {
	return x * x + y * y + z * z;
}

float Vector3::Length() const {
	return std::sqrt(LengthSquared());
}
