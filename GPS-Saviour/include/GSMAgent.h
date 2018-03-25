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

/**
 * @brief The GSMAgent class handles all GSM-functions within this project
 *
 * The GSMAgent class handles all GSM functionality for this project.
 * This includes an SSH inspired authentification and the Definitions of every
 * GSM-Package used in this Program
 * He also store and manage all unlocked Telephonenumbers
 */
class GSMAgent {
    public:
        /* --- constructors / destructors --- */
        GSMAgent() {};

        /* --- miscellaneous --- */
        void init(vector<int> partnerTelephoneNumbers_, int telephoneNumber_);

        /* --- request and receive data --- */
        void sendRequestForAuth() const;
        void sendRequestForStartLogging() const;
        void sendRequestForStopLogging() const;
        void sendRequestForSingleData() const;
        void sendRequestForSingleDataArray(const vector<GeoData> &timestempsToSend_) const;
        void sendRequestForStartContiniouslyData() const;
        void sendRequestForStopContiniouslyData() const;
        void sendData(const vector<GeoData>& dataToSend_) const;
        void receiveData();
        GSMPackage receiveRequest();
        void sendAuth() const;

        /* --- getters / setters --- */
        void setGSMConnectionEstablished(bool val_);
        bool getGSMConnectionEstablished() const;

        void setPartnerTelephoneNumbers(vector<int> val_);
        vector<int> getPartnerTelephoneNumbers() const;

        void setTelephoneNumber(int val_);
        int getTelephoneNumber() const;


private:
        /* --- send / receive --- */
        GSMPackage receiveGSMPackage();
        void sendGSMPackage(GSMPackage gsmPackageToSend_) const;

        /* --- authentication --- */
        bool checkAuthenticationOfRequest();

        vector<int> partnerTelephoneNumbers;
        int telephoneNumber;
        vector<GeoData> receivedData;
        PackageType lastReceivedGSMPackage;
        bool gsmConnetionEstablished;

        // for testing purposes
        TestBuffer& buffer = TestBuffer::getInstance();


};

#endif // GSMAgent_H
