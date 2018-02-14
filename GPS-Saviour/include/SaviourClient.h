/**
 * SaviourClient.h
 * Purpose: defines class SaviourClient
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#ifndef SaviourClient_H
#define SaviourClient_H

#include <iostream>
#include "Types.h"
#include "GSMAgent.h"

using namespace std;

class SaviourClient {
    public:
        /* --- constructors / destructors --- */
        SaviourClient() {};
        void init();

        /* --- main execution function --- */
        void execute();

        /* --- send requests --- */
        void sendRequestForData();
        void sendRequestForLogging();

        /* --- getters / setters --- */
        void setPartnerTelephoneNumbers(vector<int> val_);
        vector<int> getPartnerTelephoneNumbers() const;

        void setTelephoneNumber(int val_);
        int getTelephoneNumber() const;

    private:
        GSMAgent gsmAgent;



};

#endif // SaviourClient_H
