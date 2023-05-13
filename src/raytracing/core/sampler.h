#ifndef SAMPLER_H_
#define SAMPLER_H_

#include <basic/util/rng.h>
class Point2;

class Sampler {
public:
    RNG rng;

    Point2 Get2D() {
        return { rng.get(), rng.get() };
    }
};
#endif // SAMPLER_H_