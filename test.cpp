#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

#include "GenerateParameters.h"
#include "FrameAndSend.h"

// include hpp file of battery charging parameter

TEST_CASE("Test case to verify voltage value reflects from file to the console properly \n")
{
  REQUIRE(GetVoltageOfElement(0) == 4.2);
  REQUIRE(GetVoltageOfElement(6) == 3.4);
  REQUIRE(GetVoltageOfElement(4) == 3.8);
  REQUIRE(GetVoltageOfElement(2) == 3.7);
}

TEST_CASE("Test case to verify current value reflects from file to the console properly \n")
{
  REQUIRE(GetCurrentOfElement(0) == 18.7999);
  REQUIRE(GetCurrentOfElement(6) == 16,700001);
  REQUIRE(GetCurrentOfElement(4) == 11.70000);
  REQUIRE(GetCurrentOfElement(2) == 15.90000);
}

TEST_CASE("Just print the value in the console \n")
{
  TransmitDataToConsole();
}
