#ifndef TUPLE_HPP_
#define TUPLE_HPP_


class Tuple
{
public:
    Tuple() {};
    Tuple(const float x, const float y, const float z, float w) : _x(x), _y(y), _z(z), _w(w) {};
    ~Tuple() = default;

    float x() const { return _x; }
    float y() const { return _y; }
    float z() const { return _z; }
    float w() const { return _w; }

    bool isVector() const;
    bool isPoint()  const;

private:
    float _x, _y, _z, _w;
};

class Vector : public Tuple
{
public:
    Vector() {};
    Vector(const float x, const float y, const float z) : Tuple(x, y, z, 0.0f) {};
    Vector(const Tuple& t) : Tuple(t) {};
    ~Vector() = default;

    float magnitude() const;
    void  normalize();
    float dot(const Vector& v) const;

    static Vector normalize(const Vector& v);
    static float  dot(const Vector& a, const Vector& b);
    static Vector cross(const Vector& a, const Vector& b);
};

class Point : public Tuple
{
public:
    Point() {};
    Point(const float x, const float y, const float z) : Tuple(x, y, z, 1.0f) {};
    Point(const Tuple& t) : Tuple(t) {};
    ~Point() = default;
};

bool operator==(const Tuple& l, const Tuple& r);
Tuple operator+(const Tuple& l, const Tuple& r);
Tuple operator-(const Tuple& l, const Tuple& r);
Tuple operator-(const Tuple& a);
Tuple operator*(const Tuple& l, const float& s);
Tuple operator/(const Tuple& l, const float& s);


#endif
