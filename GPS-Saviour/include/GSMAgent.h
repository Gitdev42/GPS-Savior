/**
 * GSMAgent.h
 * Purpose: defines class GSMAgent
 *
 * @author TODO2
 * @version 1.0
 */

#ifndef GSMAgent_H
#define GSMAgent_H

#include <iostream>
#include <vector>
//-----
#include "Types.h"
#include "GSMPackage.h"
#include "TestBuffer.h"


using namespace std;

class GSMAgent {
    public:
        /* --- constructors / destructors --- */
        GSMAgent() {};

        /* --- miscellaneous --- */
        void init(vector<int> partnerTelephoneNumbers_, int telephoneNumber_);

        /* --- request and receive data --- */
        GSMPackage sendRequestForLogging();
        GSMPackage sendRequestForData();
        GSMPackage sendData();
        void receiveData(GSMPackage gsmPackageToReceive_);
        void receiveRequest(GSMPackage gsmPackageToReceive_);

        /* --- getters / setters --- */
        void setPartnerTelephoneNumbers(vector<int> val_);
        vector<int> getPartnerTelephoneNumbers() const;

        void setTelephoneNumber(int val_);
        int getTelephoneNumber() const;


private:
        /* --- send / receive --- */
        GSMPackage receiveGSMPackage();
        void sendGSMPackage(GSMPackage gsmPackageToSend_);

        /* --- authentication --- */
        bool checkAuthenticationOfRequest();

        vector<int> partnerTelephoneNumbers;
        int telephoneNumber;
        vector<GeoData> receivedData;

        // for testing purposes
        TestBuffer& buffer = TestBuffer::getInstance();


};

#endif // GSMAgent_H
