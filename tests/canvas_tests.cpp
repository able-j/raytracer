#include <catch2/catch_test_macros.hpp>
#include "../src/canvas.hpp"
#include "../src/color.hpp"
#include "../src/math.hpp"

SCENARIO("Creating a canvas", "[canvas]")
{
    GIVEN("c <- canvas(10, 20)")
    {
        const auto c = Canvas(10, 20);

        THEN("c.width = 10, c.height = 20, every pixel of c is color(0, 0, 0)")
        {
            REQUIRE(epsilonEquals(c.width(), 10));
            REQUIRE(epsilonEquals(c.height(), 20));

            const auto black = Color(0, 0, 0);
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    REQUIRE(c.pixelAt(i, j) == black);
                }
            }
        }
    }
}

SCENARIO("Writing pixels to a canvas", "[canvas]")
{
    GIVEN("c <- canvas(10, 20), red <- color(1, 0, 0)")
    {
        auto c = Canvas(10, 20);
        const auto red = Color(1, 0, 0);

        WHEN("write_pixel(c, 2, 3, red)")
        {
            c.writePixel(2, 3, red);

            THEN("pixel_at(c, 2, 3) = red")
            {
                REQUIRE(c.pixelAt(2, 3) == red);
            }
        }
    }
}
