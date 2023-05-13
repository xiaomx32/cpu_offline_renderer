#ifndef MATHTOOL_H_
#define MATHTOOL_H_

#include <limits>
#include <cmath>
#include <numbers>

constexpr float ShadowEpsilon = 0.0001f;
constexpr float Pi = std::numbers::pi;
constexpr float InvPi = std::numbers::inv_pi;
constexpr float Inv2Pi = 0.15915494309189533577f;
constexpr float Inv4Pi = 0.07957747154594766788f;
constexpr float PiOver2 = 1.57079632679489661923f;
constexpr float PiOver4 = 0.78539816339744830961f;
constexpr float Sqrt2 = 1.41421356237309504880f;

const float MachineEpsilon = std::numeric_limits<float>::epsilon() * 0.5;
const float MaxFloat = std::numeric_limits<float>::max();
const float Infinity = std::numeric_limits<float>::infinity();

inline double Clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

inline float Lerp(float t, float v1, float v2) {
	return (1 - t) * v1 + t * v2;
}

inline float Radians(float deg) { return (Pi / 180) * deg; }
inline float Degrees(float rad) { return (180 / Pi) * rad; }

inline float RandomDouble() {
    return rand() / (RAND_MAX + 1.0);
}

inline float RandomDouble(double min, double max) {
    return min + (max - min) * RandomDouble();
}
#endif // MATHTOOL_H_
