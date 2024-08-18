#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <random> // for std::mt19937, std::random_device, std::seed_seq, std::uniform_int_distribution

namespace Random
{
    inline std::mt19937 generate()
    {
        std::random_device rd {};
        std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
        return std::mt19937 {ss};
    }

    inline std::mt19937 mt {generate()};

    inline int getInteger(int min, int max)
    {
        return std::uniform_int_distribution{min, max}(mt);
    }
}

#endif