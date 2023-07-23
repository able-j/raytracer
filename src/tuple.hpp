#ifndef TUPLE_H_
#define TUPLE_H_


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
    Vector(const float x, const float y, const float z) : Tuple(x, y, z, 0.0f) {};
    Vector(const Tuple& t) : Tuple(t) {};

    float magnitude() const;
    Vector normalize() const;
};

class Point : public Tuple
{
public:
    Point(const float x, const float y, const float z) : Tuple(x, y, z, 1.0f) {};
};

bool operator==(const Tuple l, const Tuple r);
Tuple operator+(const Tuple l, const Tuple r);
Tuple operator-(const Tuple l, const Tuple r);
Tuple operator-(const Tuple a);
Tuple operator*(const Tuple l, const float s);
Tuple operator/(const Tuple l, const float s);


#endif // TUPLE_H_
