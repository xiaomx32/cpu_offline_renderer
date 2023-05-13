// #ifndef LIGHT_H_
// #define LIGHT_H_

// #include <optional>
// #include <basic/vector/point3.h>

// using Spectrum = Vector3;

// class Interaction;

// struct light_sample {
//     Vector3 dir;
//     Vector3 normal;
//     float distance;
//     float pdf;
//     Spectrum radiance;
// };

// struct Light {
// public:
//     enum Flags
//     {
//         delta_position  = 0b0001,
//         delta_direction = 0b0010,
//         area            = 0b0100,
//         infinite        = 0b1000
//     };

//     Flags flag;

// public:
//     Light(Flags flag);

//     virtual ~Light() = default;

//     virtual Spectrum Li(const hit_record& record, const Vector3f& w) const = 0;
//     // dir, distance, pdf
//     virtual std::optional<light_sample> sample_li(const Point3f& p, const Point2f& random) const = 0;

//     virtual f32 pdf_li(const Point3f& p) const = 0;
// };

// #endif // LIGHT_H_