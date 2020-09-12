//
// Created by cirkul on 09.09.2020.
//

#include <iostream>
#include "Polynomial.h"

using namespace std;

Polynomial Polynomial::operator/(const Polynomial divider) {
    Polynomial result;

    try {
        if (this->coefArray.size() < divider.coefArray.size())
            throw "Invalid data: dividend is less than divider";
    }

    catch (const char *exception) {
        cout << "Division Error: " << exception <<endl;
        result.coefArray.resize(1);
        return result;
    }

    result.coefArray.resize(this->coefArray.size() - divider.coefArray.size() + 1);

    for (int i = 0; i < result.coefArray.size(); ++i) {
        Polynomial buff;
        result.coefArray[i] = this->coefArray[0] / divider.coefArray[0];
        buff.coefArray.resize(this->coefArray.size());
        for (int j = 0; j < divider.coefArray.size(); ++j) {
            buff.coefArray[j] = result.coefArray[i] * divider.coefArray[j];
        }
        for (int j = 0; j < this->coefArray.size(); ++j) {
            this->coefArray[j] -= buff.coefArray[j];
        }
        for (int j = 0; j < this->coefArray.size() - 1; ++j) {
            this->coefArray[j] = this->coefArray[j + 1];
        }
        this->coefArray.pop_back();
    }

    return result;
}

Polynomial Polynomial::operator/=(const Polynomial divider) {
    Polynomial result;

    try {
        if (this->coefArray.size() < divider.coefArray.size())
            throw "Invalid data: dividend is less than divider";
    }

    catch (const char *exception) {
        cout << "Division Error: " << exception << endl;
        this->coefArray.resize(1);
        return *this;
    }

    result.coefArray.resize(this->coefArray.size() - divider.coefArray.size() + 1);

    for (int i = 0; i < result.coefArray.size(); ++i) {
        Polynomial buff;
        result.coefArray[i] = this->coefArray[0] / divider.coefArray[0];
        buff.coefArray.resize(this->coefArray.size());
        for (int j = 0; j < divider.coefArray.size(); ++j) {
            buff.coefArray[j] = result.coefArray[i] * divider.coefArray[j];
        }
        for (int j = 0; j < this->coefArray.size(); ++j) {
            this->coefArray[j] -= buff.coefArray[j];
        }
        for (int j = 0; j < this->coefArray.size() - 1; ++j) {
            this->coefArray[j] = this->coefArray[j + 1];
        }
        this->coefArray.pop_back();
    }
    *this = result;
    this->refactor();
    return *this;
}
