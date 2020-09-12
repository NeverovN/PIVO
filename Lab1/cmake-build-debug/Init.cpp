//
// Created by cirkul on 09.09.2020.
//

#include "Polynomial.h"

void Polynomial::init(Polynomial value, int power) {
    this->coefArray.resize(power);
    for (int i = this->coefArray.size() - 1; i >= 0; --i) {
        if (i >= this->coefArray.size() - value.coefArray.size())
            this->coefArray[i] = value.coefArray[i - this->coefArray.size() + value.coefArray.size()];
        else
            this->coefArray[i] = 0;
    }
}