/**
 * GPSAgent.cpp
 * Purpose: implements class GPSAgent
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/GPSAgent.h"


/* --- getters / setters --- */



void GPSAgent::init() {
    cout << "initialized GPSAgent" << endl;
}

void GPSAgent::receiveGeoData() {
    GeoData receivedData;
    receivedData = convertReceivedDataIntoGeoData();
    saveGeoData(receivedData);
 }


void GPSAgent::saveGeoData(GeoData receivedData) {
    cout << "GeoData Dummy received" << endl;
    GeoData data;
    data.setLongitude(receivedData.getLongitude());
    data.setLatitude(receivedData.getLatitude());
    data.setHeight(receivedData.getHeight());
    data.setCTime(receivedData.getCTime());
    storedGeoData.push_back(data);


}

GeoData GPSAgent::convertReceivedDataIntoGeoData() const
{

}
