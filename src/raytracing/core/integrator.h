#ifndef INTEGRATOR_H_
#define  INTEGRATOR_H_

#include <basic/ray/ray.h>

class Scene;
class Sampler;

class Integrator {
public:
    virtual ~Integrator() = default;

    virtual Spectrum Li(const Ray& ray_, const Scene& scene_, Sampler& sampler_) const = 0;
};
#endif // INTEGRATOR_h_