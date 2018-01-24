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

using namespace std;

class GSMAgent {
    public:
        /* --- constructors / destructors --- */
        GSMAgent() {};

        /* --- miscellaneous --- */
        void init();
        bool checkRequestForAuthentication();
        void requestData();
        void sendData();
        void requestLoggingAndContinousData();
        void sendContinousData();

private:


};

#endif // GSMAgent_H
