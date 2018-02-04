/**
 * TestBuffer.h
 * Purpose: defines class TestBuffer
 *
 * @author Wall.Of.Death
 * @version 1.0 20160704
 */

#ifndef TESTBUFFER_H
#define TESTBUFFER_H

#include "GSMPackage.h"
#include "GeoData.h"

#include <stdlib.h>     /* srand, rand */

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif


/**
 * TestBuffer class
 * @brief TestBuffer works as a buffer for test data
 * It is designed by the design pattern singleton.
 */
class TestBuffer {
    public:
        /* --- needed to create a singleton --- */
        static TestBuffer& getInstance() {
            static TestBuffer _instance;
            return _instance;
        }
        ~TestBuffer() {}


        GeoData createDummyGeoData();

        GSMPackage getGsmPackage() const;
        void setGsmPackage(const GSMPackage &val_);

        GeoData getGeoData() const;
        void setGeoData(const GeoData &val_);

private:
        /* --- needed to create a singleton --- */
        TestBuffer() {};       // must be private to avoid the creation of TestBuffer from the outside by the constructor
                               // use 'protected' if you want to inherit from this class
        TestBuffer            (const TestBuffer& TestBuffer_); // must be private to avoid creation of another TestBuffer-instance by copy-constructor
        TestBuffer& operator= (const TestBuffer& TestBuffer_); // must be private to avoid creating an new TestBuffer-instance by copying

        /* --- dummy test functions --- */
        unsigned int getTimeMs64() const;

        /* --- member variables ---*/
        GSMPackage gsmPackage;
        GeoData geoData;


};

#endif // TESTBUFFER_H
