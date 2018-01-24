/**
 * GSMPackage.h
 * Purpose: defines class GSMPackage
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef GSMPACKAGE_H
#define GSMPACKAGE_H
#include "Types.h"
#include "GeoData.h"
#include <vector>

using namespace std;

class GSMPackage {
    public:
        /* --- constructors / destructors --- */
        GSMPackage() {};

        /* --- miscellaneous --- */

        /* --- getters / setters --- */
        void setPackageType(PackageType packageType_);
        PackageType getPackageType();

        void setGeoDataToSend(GeoData geoDataToSend_);
        GeoData getGeoDataToSend();

        vector<int> getReceipientTelephoneNumbers() const;
        void setReceipientTelephoneNumbers(const vector<int> &val_);

        int getSenderTelephoneNumber() const;
        void setSenderTelephoneNumber(int val_);

private:
        PackageType packageType;
        vector<GeoData> geoDataToSend;
        vector<int> receipientTelephoneNumbers;
        int senderTelephoneNumber;

};

#endif // GSMPACKAGE_H
