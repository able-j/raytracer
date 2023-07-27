#include "color.hpp"

Color operator*(const Color& c1, const Color& c2)
{
    return Color(c1.r() * c2.r(), c1.g() * c2.g(), c1.b() * c2.b());
}
