#ifndef RNG_H_
#define RNG_H_

#include <random>

class RNG {
public:
    std::mt19937 rng;
    std::uniform_real_distribution<float> dist;

    // RNG() : RNG(std::random_device{}()) {}
    RNG(unsigned int seed) : rng(seed) {}
    RNG(const RNG&) = delete;
    RNG& operator=(const RNG&) = delete;

    float get() {
        return dist(rng);
    }

    // RNG clone() const noexcept {
    //     RNG ret;
    //     return ret;
    // }
};
#endif // RNG_H_
