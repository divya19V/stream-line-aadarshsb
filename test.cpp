#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

#include "GenerateParameters.h"
#include "FrameAndSend.h"

// include hpp file of battery charging parameter

TEST_CASE("Test case to verify voltage value reflects from file to the console properly \n")
{
  REQUIRE(GetVoltageOfElement(0,PARAM_VOLTAGE ) == 4.2f);
  REQUIRE(GetVoltageOfElement(6,PARAM_VOLTAGE ) == 3.4f);
  REQUIRE(GetVoltageOfElement(4,PARAM_VOLTAGE ) == 3.8f);
  REQUIRE(GetVoltageOfElement(2,PARAM_VOLTAGE ) == 3.7f);
}

TEST_CASE("Test case to verify current value reflects from file to the console properly \n")
{
  REQUIRE(GetCurrentOfElement(0,PARAM_CURRENT ) == 18.8f);
  REQUIRE(GetCurrentOfElement(6,PARAM_CURRENT ) == 16.700001f);
  REQUIRE(GetCurrentOfElement(4,PARAM_CURRENT ) == 11.7f);
  REQUIRE(GetCurrentOfElement(2,PARAM_CURRENT ) == 15.9f);
}

TEST_CASE("Just print the value in the console \n")
{ 
  //Print the results in the console
  TransmitDataToConsole();
}
