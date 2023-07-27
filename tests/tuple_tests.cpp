#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include "../src/tuple.hpp"
#include "../src/math.hpp"

/* Points & Vectors (tuple) */
SCENARIO("A tuple with w=1.0 is a point", "[tuple]")
{
    GIVEN("a <- tuple(4.3, -4.2, 3.1, 1.0)")
    {
        const auto a = Tuple(4.3, -4.2, 3.1, 1.0);

        THEN("a.x = 4.3, a.y = -4.2, a.z = 3.1, a.w = 1.0, a is a point, a is not a vector")
        {
            REQUIRE(epsilonEquals(a.x(), 4.3));
            REQUIRE(epsilonEquals(a.y(), -4.2));
            REQUIRE(epsilonEquals(a.z(), 3.1));
            REQUIRE(epsilonEquals(a.w(), 1.0));
            REQUIRE(a.isPoint());
            REQUIRE(!a.isVector());
        }
    }
}

SCENARIO("A tuple with w=0 is a vector", "[tuple]")
{
    GIVEN("a <- tuple(4.3, -4.2, 3.1, 0.0)")
    {
        const auto a = Tuple(4.3, -4.2, 3.1, 0.0);

        THEN("a.x = 4.3, a.y = -4.2, a.z = 3.1, a.w = 1.0, a is not a point, a is a vector")
        {
            REQUIRE(epsilonEquals(a.x(), 4.3));
            REQUIRE(epsilonEquals(a.y(), -4.2));
            REQUIRE(epsilonEquals(a.z(), 3.1));
            REQUIRE(epsilonEquals(a.w(), 0.0));
            REQUIRE(a.isVector());
            REQUIRE(!a.isPoint());
        }
    }
}

SCENARIO("point() creates tuples with w=1", "[tuple]")
{
    GIVEN("p <- point(4, -4, 3)")
    {
        const auto a = Point(4, -4, 3);
        const auto p = Tuple(4, -4, 3, 1);

        THEN("p = tuple(4, -4, 3, 1)")
        {
            REQUIRE(a == p);
        }
    }
}

SCENARIO("vector() creates tuples with w=0", "[tuple]")
{
    GIVEN("v <- vector(4, -4, 3)")
    {
        const auto a = Vector(4, -4, 3);
        const auto v = Tuple(4, -4, 3, 0);

        THEN("v = tuple(4, -4, 3, 0)")
        {
            REQUIRE(a == v);
        }
    }
}

/* OPERATIONS */

/* Adding Tuples */
SCENARIO("Adding two tuples", "[tuple]")
{
    GIVEN("a1 <- tuple(3, -2, 5, 1), a2 <- tuple(-2, 3, 1, 0)")
    {
        const auto a1 = Tuple(3, -2, 5, 1);
        const auto a2 = Tuple(-2, 3, 1, 0);

        THEN("a1 + a2 = tuple(-1, 1, 6, 1)")
        {
            REQUIRE(a1 + a2 == Tuple(1, 1, 6, 1));
        }
    }
}


/* Subtracting Tuples*/
SCENARIO("Subtracting two points", "[tuple]")
{
    GIVEN("p1 <- point(3, 2, 1), p2 <- point(5, 6, 7)")
    {
        const auto p1 = Point(3, 2, 1);
        const auto p2 = Point(5, 6, 7);

        THEN("p1 - p2 = vector(-2, -4, -6)")
        {
            REQUIRE(p1 - p2 == Vector(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting a vector from a point", "[tuple]")
{
    GIVEN("p <- point(3, 2, 1), v <- vector(5, 6, 7)")
    {
        const auto p = Point(3, 2, 1);
        const auto v = Vector(5, 6, 7);

        THEN("p - v = point(-2, -4, -6)")
        {
            REQUIRE(p - v == Point(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting two vectors", "[tuple]")
{
    GIVEN("v1 <- vector(3, 2, 1), v2 <- vector(5, 6, 7)")
    {
        const auto v1 = Vector(3, 2, 1);
        const auto v2 = Vector(5, 6, 7);

        THEN("v1 - v2 = vector(-2, -4, -6)")
        {
            REQUIRE(v1 - v2 == Vector(-2, -4, -6));
        }
    }
}

/* Negating Tuples */
SCENARIO("Subtracting a vector from the zero vector", "[tuple]")
{
    GIVEN("zero <- vector(0, 0, 0), v <- vector(1, -2, 3)")
    {
        const auto zero = Vector(0, 0, 0);
        const auto v    = Vector(1, -2, 3);

        THEN("zero - v = vector(-1, 2, -3)")
        {
            REQUIRE(zero - v == Vector(-1, 2, -3));
        }
    }
}

SCENARIO("Negating a tuple", "[tuple]")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        const auto a = Tuple(1, -2, 3, -4);

        THEN("-a = tuple(-1, 2, -3, 4)")
        {
            REQUIRE(-a == Tuple(-1, 2, -3, 4));
        }
    }
}

/* Scalar Multiplication and Division */
SCENARIO("Multiplying a tuple by a scalar", "[tuple]")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        const auto a = Tuple(1, -2, 3, -4);

        THEN("a * 3.5 = tuple(3.5, -7, 10.5, -14)")
        {
            REQUIRE(a * 3.5 == Tuple(3.5, -7, 10.5, -14));
        }
    }
}

SCENARIO("Multiplying a tuple by a fraction", "[tuple]")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        const auto a = Tuple(1, -2, 3, -4);

        THEN("a * 0.5 = tuple(0.5, -1, 1.5, -2)")
        {
            REQUIRE(a * 0.5 == Tuple(0.5, -1, 1.5, -2));
        }
    }
}

SCENARIO("Dividing a tuple by a scalar", "[tuple]")
{
    GIVEN("a <- tuple(1, -2, 3, -4)")
    {
        const auto a = Tuple(1, -2, 3, -4);

        THEN("a / 2 = tuple(0.5, -1, 1.5, -2)")
        {
            REQUIRE(a / 2 == Tuple(0.5, -1, 1.5, -2));
        }
    }
}

/* Magnitude */
SCENARIO("Computing the magnitude of vector(1, 0, 0)", "[tuple]")
{
    GIVEN("v <- vector(1, 0, 0)")
    {
        const auto v = Vector(1, 0, 0);

        THEN("magnitude(v) = 1")
        {
            REQUIRE(epsilonEquals(v.magnitude(), 1));
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 1, 0)", "[tuple]")
{
    GIVEN("v <- vector(0, 1, 0)")
    {
        const auto v = Vector(0, 1, 0);

        THEN("magnitude(v) = 1")
        {
            REQUIRE(epsilonEquals(v.magnitude(), 1));
        }
    }
}

SCENARIO("Computing the magnitude of vector(0, 0, 1)", "[tuple]")
{
    GIVEN("v <- vector(0, 0, 1)")
    {
        const auto v = Vector(0, 0, 1);

        THEN("magnitude(v) = 1")
        {
            REQUIRE(epsilonEquals(v.magnitude(), 1));
        }
    }
}

SCENARIO("Computing the magnitude of vector(1, 2, 3)", "[tuple]")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        const auto v = Vector(1, 2, 3);

        THEN("magnitude(v) = sqrt(14)")
        {
            REQUIRE(epsilonEquals(v.magnitude(), std::sqrt(14)));
        }
    }
}

SCENARIO("Computing the magnitude of vector(-1, -2, -3)", "[tuple]")
{
    GIVEN("v <- vector(-1, -2, -3)")
    {
        const auto v = Vector(-1, -2, -3);

        THEN("magnitude(v) = sqrt(14)")
        {
            REQUIRE(epsilonEquals(v.magnitude(), std::sqrt(14)));
        }
    }
}

/* Normalization */
SCENARIO("Normalizing vector(4, 0, 0) gives (1, 0, 0)", "[tuple]")
{
    GIVEN("v <- vector(4, 0, 0)")
    {
        auto v = Vector(4, 0, 0);

        THEN("normalize(v) = vector(1, 0, 0)")
        {
            REQUIRE(Vector::normalize(v) == Vector(1, 0, 0));

            v.normalize();
            REQUIRE(v == Vector(1, 0, 0));
        }
    }
}

SCENARIO("Normalizing vector(1, 2, 3)", "[tuple]")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        auto v = Vector(1, 2, 3);

        THEN("normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)")
        {
            REQUIRE(Vector::normalize(v) == Vector(0.26726, 0.53452, 0.80178));

            v.normalize();
            REQUIRE(v == Vector(0.26726, 0.53452, 0.80178));
        }
    }
}

SCENARIO("The magnitude of a normalized vector", "[tuple]")
{
    GIVEN("v <- vector(1, 2, 3)")
    {
        auto v = Vector(1, 2, 3);

        WHEN("norm <- normalize(v)")
        {
            const auto norm = Vector::normalize(v);

            THEN("magnitude(norm) = 1")
            {
                REQUIRE(epsilonEquals(norm.magnitude(), 1));

                v.normalize();
                REQUIRE(epsilonEquals(v.magnitude(), 1));
            }
        }
    }
}

/* Dot Product */
SCENARIO("The dot product of two tuples", "[tuple]")
{
    GIVEN("a <- vector(1, 2, 3), b <- vector(2, 3, 4)")
    {
        const auto a = Vector(1, 2, 3);
        const auto b = Vector(2, 3, 4);

        THEN("dot(a, b) = 20")
        {
            REQUIRE(epsilonEquals(Vector::dot(a, b), 20));
            REQUIRE(epsilonEquals(a.dot(b), 20));
            REQUIRE(epsilonEquals(b.dot(a), 20));
        }
    }
}

/* Cross Product */
SCENARIO("The cross product of two vectors", "[tuple]")
{
    GIVEN("a <- vector(1, 2, 3), b <- vector(2, 3, 4)")
    {
        const auto a = Vector(1, 2, 3);
        const auto b = Vector(2, 3, 4);

        THEN("cross(a, b) = vector(-1, 2, -1), cross(b, a) = vector(1, -2, 1)")
        {
            REQUIRE(Vector::cross(a, b) == Vector(-1, 2, -1));
            REQUIRE(Vector::cross(b, a) == Vector(1, -2, 1));
        }
    }
}
