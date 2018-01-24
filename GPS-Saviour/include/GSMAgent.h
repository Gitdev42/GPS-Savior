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
#include "Types.h"
#include <vector>


using namespace std;

class GSMAgent {
    public:
        /* --- constructors / destructors --- */
        GSMAgent() {};

        /* --- miscellaneous --- */
        void init(vector<int> partnerTelephoneNumbers_, int telephoneNumber_);

        /* --- request and receive data --- */
        void sendRequestForLogging();
        void sendRequesForData();
        void sendData();
        void receiveData();
        void receiveRequest();

        /* --- getters / setters --- */
        void setPartnerTelephoneNumbers(vector<int> val_);
        vector<int> getPartnerTelephoneNumbers() const;

        void setTelephoneNumber(int val_);
        int getTelephoneNumber() const;


private:
        /* --- send / receive --- */
        void receiveGSMPackage();
        void sendGSMPackage();

        /* --- authentication --- */
        bool checkAuthenticationOfRequest();

        vector<int> partnerTelephoneNumbers;
        int telephoneNumber;


};

#endif // GSMAgent_H
