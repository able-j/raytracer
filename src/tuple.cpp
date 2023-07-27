#include "tuple.hpp"
#include "math.hpp"

#include <cmath>

bool Tuple::isVector() const
{
    return epsilonEquals(0.0f, _w);
}

bool Tuple::isPoint() const
{
    return epsilonEquals(1.0f, _w);
}

bool operator==(const Tuple& l, const Tuple& r)
{
    return epsilonEquals(l.x(), r.x()) &&
        epsilonEquals(l.y(), r.y()) &&
        epsilonEquals(l.z(), r.z()) &&
        epsilonEquals(l.w(), r.w());
}

Tuple operator+(const Tuple& l, const Tuple& r)
{
    return Tuple(l.x() + r.x(), l.y() + r.y(), l.z() + r.z(), l.w() + r.w());
}

Tuple operator-(const Tuple& l, const Tuple& r)
{
    return Tuple(l.x() - r.x(), l.y() - r.y(), l.z() - r.z(), l.w() - r.w());
}

Tuple operator-(const Tuple& a)
{
    return Tuple(-a.x(), -a.y(), -a.z(), -a.w());
}

Tuple operator*(const Tuple& l, const float& s) // scalar
{
    return Tuple(l.x() * s, l.y() * s, l.z() * s, l.w() * s);
}

Tuple operator/(const Tuple& l, const float& s) // scalar
{
    return Tuple(l.x() / s, l.y() / s, l.z() / s, l.w() / s);
}

/* Vector class member functions */
float Vector::magnitude() const
{
    return std::sqrt(this->x() * this->x() + this->y() * this->y() + this->z() * this->z());
}

void Vector::normalize()
{
    const float magnitude = this->magnitude();
    if (!epsilonEquals(magnitude, 0))
    {
        *this = *this / magnitude;
    }
}

Vector Vector::normalize(const Vector& v)
{
    const float magnitude = v.magnitude();
    if (!epsilonEquals(magnitude, 0))
    {
        return v / magnitude;
    }
}

float Vector::dot(const Vector& v) const
{
    return (this->x() * v.x()) + (this->y() * v.y()) + (this->z() * v.z());
}

float Vector::dot(const Vector& a, const Vector& b)
{
    return (a.x() * b.x())
        + (a.y() * b.y())
        + (a.z() * b.z());
}

Vector Vector::cross(const Vector& a, const Vector& b)
{
    return Vector((a.y() * b.z()) - (a.z() * b.y()),
                  (a.z() * b.x()) - (a.x() * b.z()),
                  (a.x() * b.y()) - (a.y() * b.x()));
}
