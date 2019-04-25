#pragma once

namespace smallpt
{

class RNG
{
public:

    //---------------------------------------------------------------------
    // Constructors and Destructors
    //---------------------------------------------------------------------

    DEVICE
    explicit RNG(std::uint32_t seed = 606418532u) noexcept
    {
        Seed(seed);
    }
    RNG(const RNG &rng) noexcept = default;
    RNG(RNG &&rng) noexcept = default;
    ~RNG() = default;

    //---------------------------------------------------------------------
    // Assignment Operators
    //---------------------------------------------------------------------

    RNG &operator=(const RNG &rng) = delete;
    RNG &operator=(RNG &&rng) = delete;

    //---------------------------------------------------------------------
    // Member Methods
    //---------------------------------------------------------------------

    DEVICE
    void Seed(uint32_t seed) noexcept
    {
        curand_init(seed, 0u, 0u, &state);
    }

    DEVICE
    double Uniform() noexcept
    {
        return curand_uniform_double(&state);
    }

private:

    //---------------------------------------------------------------------
    // Member Variables
    //---------------------------------------------------------------------

    curandState state;
};

}