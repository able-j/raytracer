#include <catch2/catch_test_macros.hpp>
#include "../src/matrix.hpp"
#include "../src/math.hpp"

SCENARIO("Constructing and inspecting a 4x4 matrix", "[matrix]")
{
    GIVEN("the following 4x4 matrix M:\n|  1   |  2   |  3   |  4   |\n|  5.5 |  6.5 |  7.5 |  8.5 |\n|  9   | 10   | 11   | 12   |\n| 13.5 | 14.5 | 15.5 | 16.5 |")
    {
        Matrix<4, 4> M = {1, 2, 3, 4,
                          5.5, 6.5, 7.5, 8.5,
                          0, 10, 11, 12,
                          13.5, 14.5, 15.5, 16.5};

        THEN("M[0,0] = 1, M[0,3] = 4, M[1,0] = 5.5, M[1,2] = 7.5, M[2,2] = 11, M[3,0] = 13.5, M[3,2] = 15.5")
        {
            REQUIRE(epsilonEquals(M(0, 0),    1));
            REQUIRE(epsilonEquals(M(0, 3),    4));
            REQUIRE(epsilonEquals(M(1, 0),  5.5));
            REQUIRE(epsilonEquals(M(1, 2),  7.5));
            REQUIRE(epsilonEquals(M(2, 2),   11));
            REQUIRE(epsilonEquals(M(3, 0), 13.5));
            REQUIRE(epsilonEquals(M(3, 2), 15.5));
        }
    }
}

SCENARIO("A 2x2 matrix ought to be representable", "[matrix]")
{
    GIVEN("the following 2x2 matrix M:\n| -3 |  5 |\n|  1 | -2 |")
    {
        Matrix<2, 2> M = {-3, 5,
                          1, -2};

        THEN("M[0,0] = -3, M[0,1] = 5, M[1,0] = 1, M[1,1] = -2")
        {
            REQUIRE(epsilonEquals(M(0, 0), -3));
            REQUIRE(epsilonEquals(M(0, 1),  5));
            REQUIRE(epsilonEquals(M(1, 0),  1));
            REQUIRE(epsilonEquals(M(1, 1), -2));
        }
    }
}

SCENARIO("A 3x3 matrix ought to be representable", "[matrix]")
{
    GIVEN("the following 3x3 matrix M:\n| -3 |  5 |  0 |\n|  1 | -2 | -7 |\n|  0 |  1 |  1 |")
    {
        Matrix<3, 3> M = {-3, 5, 0,
                          1, -2, -7,
                          0, 1, 1};

        THEN("M[0,0] = -3, M[1,1] = -2, M[2,2] = 1")
        {
            REQUIRE(epsilonEquals(M(0, 0), -3));
            REQUIRE(epsilonEquals(M(1, 1), -2));
            REQUIRE(epsilonEquals(M(2, 2),  1));
        }
    }
}

SCENARIO("Matrix equality with identical matrices", "[matrix]")
{
    GIVEN("the following matrix A:\n| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 8 | 7 | 6 |\n| 5 | 4 | 3 | 2 |\n, the following matrix B:\n| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 8 | 7 | 6 |\n| 5 | 4 | 3 | 2 |\n")
    {
        Matrix<4, 4> A = {1, 2, 3, 4,
                          5, 6, 7, 8,
                          9, 8, 7, 6,
                          5, 4, 3, 2};

        Matrix<4, 4> B = {1, 2, 3, 4,
                          5, 6, 7, 8,
                          9, 8, 7, 6,
                          5, 4, 3, 2};

        THEN("A = B")
        {
            REQUIRE(A == B);
        }
    }
}

SCENARIO("Matrix equality with different matrices", "[matrix]")
{
    GIVEN("the following matrix A:\n| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 8 | 7 | 6 |\n| 5 | 4 | 3 | 2 |\n, the following matrix B:\n| 2 | 3 | 4 | 5 |\n| 6 | 7 | 8 | 9 |\n| 8 | 7 | 6 | 5 |\n| 4 | 3 | 2 | 1 |\n")
    {
        Matrix<4, 4> A = {1, 2, 3, 4,
                          5, 6, 7, 8,
                          9, 8, 7, 6,
                          5, 4, 3, 2};

        Matrix<4, 4> B = {2, 3, 4, 5,
                          6, 7, 8, 9,
                          8, 7, 6, 5,
                          4, 3, 2, 1};

        THEN("A != B")
        {
            REQUIRE(A != B);
        }
    }
}
