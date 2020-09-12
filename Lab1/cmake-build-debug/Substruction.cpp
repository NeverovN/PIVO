//
// Created by cirkul on 09.09.2020.
//
#include <iostream>
#include "Polynomial.h"
using namespace std;

Polynomial Polynomial::operator - (const Polynomial subtrahend){
    Polynomial result;
    this->coefArray.size() > subtrahend.coefArray.size() ?
    result.init(*this, this->coefArray.size()) :
    result.init(*this, subtrahend.coefArray.size());
    for (int i = 0; i < subtrahend.coefArray.size(); ++i)
        result.coefArray[i + result.coefArray.size() - subtrahend.coefArray.size()] -= subtrahend.coefArray[i];
    return result;
}

Polynomial Polynomial::operator -= (const Polynomial subtrahend){
    this->coefArray.size() > subtrahend.coefArray.size() ?
    this->init(*this, this->coefArray.size()) :
    this->init(*this, subtrahend.coefArray.size());
    for (int i = 0; i < subtrahend.coefArray.size(); ++i)
        this->coefArray[i + this->coefArray.size() - subtrahend.coefArray.size()] =
                this->coefArray[i + this->coefArray.size() - subtrahend.coefArray.size()] - subtrahend.coefArray[i];

    return *this;
}
