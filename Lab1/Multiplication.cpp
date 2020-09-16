//
// Created by cirkul on 14.09.2020.
//

/*!
 * \file
 */

#include "Polynomial.h"

Polynomial Polynomial::operator * (const Polynomial multiplier) {
    Polynomial result;
    result.coefArray.resize(this->coefArray.size() + multiplier.coefArray.size() - 1);
    for (int i = 0; i < this->coefArray.size(); i++) {
        for (int j = 0; j < multiplier.coefArray.size(); j++) {
            result.coefArray[i + j] += this->coefArray[i] * multiplier.coefArray[j];
        }
    }
    return result;
}

void Polynomial::operator *= (const Polynomial multiplier) {
    Polynomial result;
    result.coefArray.resize(this->coefArray.size() + multiplier.coefArray.size() - 1);
    for (int i = 0; i < this->coefArray.size(); i++) {
        for (int j = 0; j < multiplier.coefArray.size(); j++) {
            result.coefArray[i + j] += this->coefArray[i] * multiplier.coefArray[j];
        }
    }
    *this = result;
}
