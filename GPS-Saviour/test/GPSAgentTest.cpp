/**
* GPSAgentTest.cpp
* Purpose: implements unit-tests for analysing functions of the GPSAgent-class
*
* @author gitdev42
* @version 1.0
*/

// !!!! TEST_CASE IN COMBINITION WITH REQUIRE IS LIKE A LOOP STRUCTURE !!!!
// !!!! THE TEST_CASE IS EXECUTED FOR EVERY SECTION !!!!

#include "catch.hpp"
#include "GPSAgent.h"

using namespace  std;


TEST_CASE("Test GPSAgent") {
    GPSAgent gpsA;
    gpsA.init();
    gpsA.receiveGeoData();



}
