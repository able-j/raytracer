#ifndef COLOR_HPP_
#define COLOR_HPP_

#include "tuple.hpp"

class Color : public Tuple
{
public:
    Color() {};
    Color(const float r, const float g, const float b) : Tuple(r, g, b, 0) {};
    ~Color() = default;

    float r() const { return this->x(); }
    float g() const { return this->y(); }
    float b() const { return this->z(); }
 };
;
Color operator*(const Color& c1, const Color& c2);

#endif
