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
#include "GeoData.h"
#include "TestBuffer.h"

using namespace  std;


TEST_CASE("Test GPSAgent") {


    // create gps data dummy
    TestBuffer& buffer = TestBuffer::getInstance();
    buffer.setGeoData(buffer.createDummyGeoData());

    GPSAgent gpsA;

    // receive for the first time
    gpsA.init();
    gpsA.receiveGeoData();
    vector<GeoData> storedGeoD = gpsA.getStoredGeoData();
    REQUIRE(storedGeoD.size() == 1);
    REQUIRE(storedGeoD[0].getLongitude() == buffer.getGeoData().getLongitude());
    REQUIRE(storedGeoD[0].getLatitude() == buffer.getGeoData().getLatitude());
    REQUIRE(storedGeoD[0].getHeight() == buffer.getGeoData().getHeight());
    REQUIRE(storedGeoD[0].getCTime() == buffer.getGeoData().getCTime());

    // receive same data again
    gpsA.receiveGeoData();
    storedGeoD = gpsA.getStoredGeoData();
    REQUIRE(storedGeoD.size() == 2);
    REQUIRE(storedGeoD[1].getLongitude() == buffer.getGeoData().getLongitude());
    REQUIRE(storedGeoD[1].getLatitude() == buffer.getGeoData().getLatitude());
    REQUIRE(storedGeoD[1].getHeight() == buffer.getGeoData().getHeight());
    REQUIRE(storedGeoD[1].getCTime() == buffer.getGeoData().getCTime());


    // generate new data and receive this again
    buffer.createDummyGeoData();
    gpsA.receiveGeoData();
    storedGeoD = gpsA.getStoredGeoData();
    REQUIRE(storedGeoD.size() == 3);
    REQUIRE(storedGeoD[2].getLongitude() == buffer.getGeoData().getLongitude());
    REQUIRE(storedGeoD[2].getLatitude() == buffer.getGeoData().getLatitude());
    REQUIRE(storedGeoD[2].getHeight() == buffer.getGeoData().getHeight());
    REQUIRE(storedGeoD[2].getCTime() == buffer.getGeoData().getCTime());
}
