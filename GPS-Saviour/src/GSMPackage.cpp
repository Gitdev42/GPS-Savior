/**
 * GSMPackage.cpp
 * Purpose: implements class GSMPackage
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "GSMPackage.h"
#include "Types.h"

void GSMPackage::setPackageType(PackageType packageType_) {
    packageType = packageType_;
}

PackageType GSMPackage::getPackageType() {
    return packageType;
}

void GSMPackage::setGeoDataToSend(GeoData geoDataToSend_) {
    geoDataToSend = geoDataToSend_;
}

GeoData GSMPackage::getGeoDataToSend() {
    return geoDataToSend;
}
