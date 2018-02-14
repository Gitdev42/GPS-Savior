/**
 * SaviourClient.cpp
 * Purpose: implements class SaviourClient
 *
 * @author Wall.Of.Death
 * @version 1.0
 */

#include "../include/SaviourClient.h"


/* --- constructors / destructors --- */
void SaviourClient::init() {
    vector<int> temp;
    gsmAgent.init(temp,0);
}

/* --- main execution function --- */
void SaviourClient::execute() {
    cout << "Welcome to the NeedyClient!" << endl;
    cout << "                                     /~\\            " << endl;
    cout << "                                    |oo )           " << endl;
    cout << "                                    _\\=/_           " << endl;
    cout << "                    ___            /  _  \\          " << endl;
    cout << "                   /() \\          //|/.\\|\\\\         " << endl;
    cout << "                 _|_____|_        \\\\ \\_/  ||        " << endl;
    cout << "                | | === | |        \\|\\ /| ||        " << endl;
    cout << "                |_|  O  |_|        # _ _/ #         " << endl;
    cout << "                 ||  O  ||          | | |           " << endl;
    cout << "                 ||__*__||          | | |           " << endl;
    cout << "                |~ \\___/ ~|         []|[]           " << endl;
    cout << "                /=\\ /=\\ /=\\         | | |           " << endl;
    cout << "________________[_]_[_]_[_]________/_]_[_\\__________" << endl;
    cout << "Please configure your own and your partner telephone-numbers." << endl;
    int telephoneNumber1, telephoneNumber2;
    do {
        cout << "Please enter now the telephone-number of your SaviourClient and confirm by pressing return" << endl;
        cin >> telephoneNumber1;
        cout << "Please confirm the telephone-number of your SaviourClient by retyping it and confirming by pressing return" << endl;
        cin >> telephoneNumber2;
        if (telephoneNumber1 != telephoneNumber2) {
            cout << "Please try again!" << endl;
        }
    } while (telephoneNumber1 != telephoneNumber2);
    setTelephoneNumber(telephoneNumber1);
    cout << "Thank you for configuring the SaviourClient's telephone-number." << endl;

    vector<int> partnerTelephoneNumbers;
    char yesNo;
    do {


        do {
            cout << "Now please enter your partners telephone-number and confirm by pressing return" << endl;
            cin >> telephoneNumber1;
            cout << "Please confirm the telephone-number for your partner by retyping it and confirming by pressing return" << endl;
            cin >> telephoneNumber2;
            if (telephoneNumber1 != telephoneNumber2) {
                cout << "Please try again!" << endl;
            }
        } while (telephoneNumber1 != telephoneNumber2);
        partnerTelephoneNumbers.push_back(telephoneNumber1);

        cout << "Thank you for configuring your partners telephone-number." << endl;

        do {
            cout << "Do you want to add more partner telephone-numbers?" << endl;
            cout << "Press 'y'' if you want to add another telephone-number and 'n' if not." << endl;
            cin >> yesNo;
        } while ((yesNo != 'y') && (yesNo != 'n'));



    } while (yesNo == 'y');
    setPartnerTelephoneNumbers(partnerTelephoneNumbers);

}

/* --- send requests --- */
void SaviourClient::sendRequestForData() {
    gsmAgent.sendRequestForData();
}

void SaviourClient::sendRequestForLogging() {
    gsmAgent.sendRequestForLogging();
}

/* --- getters / setters --- */
void SaviourClient::setPartnerTelephoneNumbers(vector<int> val_) {
    gsmAgent.setPartnerTelephoneNumbers(val_);
}

vector<int> SaviourClient::getPartnerTelephoneNumbers() const {
    return gsmAgent.getPartnerTelephoneNumbers();
}

void SaviourClient::setTelephoneNumber(int val_) {
    gsmAgent.setTelephoneNumber(val_);
}

int SaviourClient::getTelephoneNumber() const {
    return gsmAgent.getTelephoneNumber();
}
