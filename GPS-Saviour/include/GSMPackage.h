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

private:
        PackageType packageType;
        vector<GeoData> geoDataToSend;

};

#endif // GSMPACKAGE_H
