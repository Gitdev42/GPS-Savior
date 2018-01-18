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

using namespace std;

class GSMAgent {
    public:
        /* --- constructors / destructors --- */
        GSMAgent() {};

        /* --- getters / setters --- */
        void init();
        void requestData();
        void sendData();

private:


};

#endif // GSMAgent_H
