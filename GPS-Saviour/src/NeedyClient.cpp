/**
 * TODO1.cpp
 * Purpose: implements class TODO1
 *
 * @author TODO2
 * @version 1.0
 */

#include "../include/NeedyClient.h"


/* --- getters / setters --- */




void NeedyClient::init() {
    vector<int> temp;
    gpsAgent.init();
    gsmAgent.init(temp,0);
}

void NeedyClient::execute() {

}
