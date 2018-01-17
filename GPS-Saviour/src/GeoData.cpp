/**
 * GeoData.cpp
 * Purpose: implements class GeoData
 *
 * @author TODO2
 * @version 1.0
 */

#include "GeoData.h"


/* --- getters / setters --- */

/**
 * GeoData::getLongitude
 * @brief getter for class member longitude
 * @return returns current value of longitude
 */
double GeoData::getLongitude() const {
    return longitude;
}

/**
 * GeoData::setLongitude
 * @brief setter for class member longitude
 * @param longitude_ new value for class member longitude
 */
void GeoData::setLongitude(double longitude_) {
    longitude = longitude_;
}

/**
 * GeoData::getLatitude
 * @brief getter for class member latitude
 * @return returns current value of latitude
 */
double GeoData::getLatitude() const {
    return latitude;
}

/**
 * GeoData::setLatitude
 * @brief setter for class member height
 * @param height_ new value for class member height
 */
void GeoData::setLatitude(double latitude_) {
    latitude = latitude_;
}

/**
 * GeoData::getHeight
 * @brief getter for class member height
 * @return returns current value of height
 */
double GeoData::getHeight() const {
    return height;
}

/**
 * GeoData::setHeight
 * @brief setter for class member height
 * @param height_ new value for class member height
 */
void GeoData::setHeight(double height_) {
    height = height_;
}
