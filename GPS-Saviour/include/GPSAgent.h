/**
 * GPSAgent.h
 * Purpose: defines class GPSAgent
 *
 * @author TODO2
 * @version 1.0
 */

#ifndef GPSAgent_H
#define GPSAgent_H

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */

#include "GeoData.h"


using namespace std;

class GPSAgent {
    public:
        /* --- constructors / destructors --- */
        GPSAgent();

        /* --- miscellaneous --- */
        void init();
        void receiveGeoData();
        void receiveDataFromGPSChip() const;
        void saveGeoData(GeoData);
        GeoData convertReceivedDataIntoGeoData() const;

        /* --- getters / setters --- */
        void setConnectionEstablished(bool val_);
        bool getConnectionEstablished();

        /* --- dummy test functions --- */
        unsigned int getTimeMs64() const;

private:
    bool connectionEstablished;
    vector<GeoData> storedGeoData;

};

#endif // GPSAgent_H
