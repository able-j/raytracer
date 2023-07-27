#ifndef MATH_UTILS_HPP_
#define MATH_UTILS_HPP_

#include <cmath>

inline bool epsilonEquals(const float x, const float y)
{
    const float epsilon = 0.00001f;
    return std::abs(x - y) < epsilon;
}

#endif
