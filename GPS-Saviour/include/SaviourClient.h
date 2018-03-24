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

        /* --- initialisation / main execution function --- */
        void execute();


    private:
        GSMAgent gsmAgent;
        GSMPackage receivedGSMPackage;

        /* --- main execution function --- */
        bool checkRequestForStatusChange();
        bool checkReceivedPackage();
        PackageType checkPackageType(GSMPackage receivedGSMPackage_);
        void saveData(GSMPackage);
        void SendAnswerForAuthRequest(GSMPackage);
        void error();

};

#endif // SaviourClient_H
