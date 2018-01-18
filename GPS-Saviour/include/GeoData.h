/**
 * GeoData.h
 * Purpose: defines class GeoData
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef GEODATA_H
#define GEODATA_H



class GeoData {
    public:
        /* --- constructors / destructors --- */
        GeoData() {};

        /* --- getters / setters --- */
        double getLongitude() const;
        void setLongitude(double longitude_);

        double getLatitude() const;
        void setLatitude(double latitude_);

        double getHeight() const;
        void setHeight(double latitude_);


private:
    double longitude; // geo location longitude in decimal degree
    double latitude; // geo location latitude in decimal degree
    double height; // geo location height in meter
    int ctime; // time (unix time)

};

#endif // GEODATA_H
