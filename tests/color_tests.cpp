#include <catch2/catch_test_macros.hpp>
#include "../src/color.hpp"
#include "../src/math.hpp"

SCENARIO("Adding colors", "[color]")
{
    GIVEN("c1 <- color(0.9, 0.6, 0.75), c2 <- color(0.7, 0.1, 0.25)")
    {
        const auto c1 = Color(0.9, 0.6, 0.75);
        const auto c2 = Color(0.7, 0.1, 0.25);

        THEN("c1 + c2 = color(1.6, 0.7, 1.0)")
        {
            REQUIRE(c1 + c2 == Color(1.6, 0.7, 1.0));
        }
    }
}

SCENARIO("Subtracting colors", "[color]")
{
    GIVEN("c1 <- color(0.9, 0.6, 0.75), c2 <- color(0.7, 0.1, 0.25)")
    {
        const auto c1 = Color(0.9, 0.6, 0.75);
        const auto c2 = Color(0.7, 0.1, 0.25);

        THEN("c1 - c2 = color(0.2, 0.5, 0.5)")
        {
            REQUIRE(c1 - c2 == Color(0.2, 0.5, 0.5));
        }
    }
}

SCENARIO("Multiplying a color by a scalar", "[color]")
{
    GIVEN("c <- color(0.2, 0.3, 0.4)")
    {
        const auto c = Color(0.2, 0.3, 0.4);

        THEN("c1 * 2 = color(0.4, 0.6, 0.8)")
        {
            REQUIRE(c * 2 == Color(0.4, 0.6, 0.8));
        }
    }
}

SCENARIO("Multiplying colors", "[color]")
{
    GIVEN("c1 <- color(1, 0.2, 0.4), c2 <- color(0.9, 1, 0.1)")
    {
        const auto c1 = Color(1, 0.2, 0.4);
        const auto c2 = Color(0.9, 1, 0.1);

        THEN("c1 * c2 = color(0.9, 0.2, 0.04)")
        {
            REQUIRE(c1 * c2 == Color(0.9, 0.2, 0.04));
        }
    }
}
