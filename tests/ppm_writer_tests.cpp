#include <catch2/catch_test_macros.hpp>
#include "../src/ppm_writer.hpp"

#include <sstream>
#include <string>

SCENARIO("Constructing the PPM header")
{
    GIVEN("c <- canvas(5, 3)")
    {
        const Canvas *c = new Canvas(5, 3);
        const PPMWriter w = PPMWriter(c);

        WHEN("ppm <- canvas_to_ppm(c)")
        {
            std::ostringstream oss;
            w.writeStream(oss);

            THEN("lines 1-3 of ppm are P3\n5 3\n255\n")
            {
                REQUIRE(std::string("P3\n5 3\n255\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n") == oss.str());
            }
        }
    }
}

SCENARIO("Constructing the PPM pixel data")
{
    GIVEN("c <- canvas(5, 3), c1 <- color(1.5, 0, 0), c2 <- color(0, 0.5, 0), c3 <- color(-0.5, 0, 1)")
    {
        Canvas *c = new Canvas(5, 3);
        const auto c1 = Color(1.5, 0, 0);
        const auto c2 = Color(0, 0.5, 0);
        const auto c3 = Color(-0.5, 0, 1);

        WHEN("write_pixel(c, 0, 0, c1), write_pixel(c, 2, 1, c2), write_pixel(c, 4, 2, c3), ppm <- canvas_to_ppm(c)")
        {
            c->writePixel(0, 0, c1);
            c->writePixel(2, 1, c2);
            c->writePixel(4, 2, c3);

            const PPMWriter w = PPMWriter(c);

            std::ostringstream oss;
            w.writeStream(oss);

            THEN("lines 4-6 of ppm are 255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n")
            {
                REQUIRE(std::string("P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n") == oss.str());
            }
        }
    }
}

SCENARIO("Splitting long lines in PPM files")
{
    GIVEN("c <- canvas(10, 2)")
    {
        Canvas *c = new Canvas(10, 2);

        WHEN("every pixel of c is set to color(1, 0.8, 0.6), ppm <- canvas_to_ppm(c)")
        {
            c->fill(Color(1, 0.8, 0.6));

            const PPMWriter w = PPMWriter(c);

            std::ostringstream oss;
            w.writeStream(oss);

            THEN("lines 4-7 of ppm are 255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n")
            {
                REQUIRE(std::string("P3\n10 2\n255\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n") == oss.str());
            }
        }
    }
}

SCENARIO("PPM files are terminated by a newline character")
{
    GIVEN("c <- canvas(5, 3)")
    {
        const Canvas *c = new Canvas(5, 3);

        WHEN("ppm <- canvas_to_ppm(c)")
        {
            const PPMWriter w = PPMWriter(c);

            std::ostringstream oss;
            w.writeStream(oss);

            std::string ppm = oss.str();

            THEN("ppm ends with a newline character")
            {
                REQUIRE(ppm.at(ppm.length() - 1) == '\n');
            }
        }
    }
}
