#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include "../src/tuple.hpp"
#include "../src/math.hpp"
#include <catch2/catch_test_macros.hpp>

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
