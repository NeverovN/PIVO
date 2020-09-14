//
// Created by cirkul on 09.09.2020.
//

#include "Polynomial.h"

Polynomial::Polynomial() = default;

Polynomial::Polynomial(const int power, const double coefArray[]) {
    this->coefArray.resize(power + 1);
    for (int i = 0; i < this->coefArray.size(); i++)
        this->coefArray[i] = coefArray[i];
}

