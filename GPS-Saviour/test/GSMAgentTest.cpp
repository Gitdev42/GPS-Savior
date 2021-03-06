/**
* GSMAgentTest.cpp
* Purpose: implements unit-tests for analysing functions of the GSMAgent-class
*
* @author gitdev42
* @version 1.0
*/

// !!!! TEST_CASE IN COMBINITION WITH REQUIRE IS LIKE A LOOP STRUCTURE !!!!
// !!!! THE TEST_CASE IS EXECUTED FOR EVERY SECTION !!!!

#include "catch.hpp"
#include "GSMAgent.h"
#include "GPSAgent.h"

using namespace  std;


TEST_CASE("Test GSMAgent") {
    GSMAgent gsmA;
    GSMPackage gsmP;
    GeoData geoD;
    vector<GeoData> vGeoD;
    vGeoD.push_back(geoD);
    gsmP.setPackageType(PackageType::sendData);
    gsmP.setGeoDataToSend(vGeoD);
    gsmA.receiveData();
}
