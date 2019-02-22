#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/* TDD-Style*/

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3628800);
}

TEST_CASE("Sums are computed", "[sum]")
{
    SECTION("positive numbers")
    {
        REQUIRE(sum(1, 1) == 2);
        REQUIRE(sum(2, 0) == 2);
        REQUIRE(sum(10, 100) == 110);
    }

    SECTION("negative numbers")
    {
        REQUIRE(sum(3, -1) == 2);
        REQUIRE(sum(-10, 1) == 9);
        REQUIRE(sum(-3, -1) == 2);
    }
}

/* BDD-Style */

SCENARIO("Signal amplifier works correctly", "[amplify]")
{

    GIVEN("input signal")
    {
        std::vector<int> signal = {-1, 0, 1, 2, 1};

        WHEN("signal amplified by a positive constant")
        {
            std::vector<int> signal2 = amplify(signal, 2);

            THEN("values of the signal amplified properly")
            {
                REQUIRE(signal2[0] == signal[0] * 2);
                REQUIRE(signal2[1] == signal[1] * 2);
                REQUIRE(signal2[2] == signal[2] * 2);
                REQUIRE(signal2[3] == signal[3] * 2);
                REQUIRE(signal2[4] == signal[4] * 2);
            }
        }

        WHEN("signal amplified by a negative constant")
        {
            std::vector<int> signal2 = amplify(signal, -2);

            THEN("values of the signal amplified properly")
            {
                REQUIRE(signal2[0] == signal[0] * 2);
                REQUIRE(signal2[1] == signal[1] * 2);
                REQUIRE(signal2[2] == signal[2] * 2);
                REQUIRE(signal2[3] == signal[3] * 2);
                REQUIRE(signal2[4] == signal[4] * 2);
            }
        }
    }
}