//
// Created by cirkul on 12.09.2020.
//

/*!
 * \file
 */

#include "Polynomial.h"

double Polynomial::operator[](const int requiredIndex) {
    return this->coefArray[this->coefArray.size() - requiredIndex - 1];
}