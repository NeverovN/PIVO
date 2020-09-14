//
// Created by cirkul on 14.09.2020.
//

#include "Polynomial.h"

Polynomial Polynomial::operator + (const Polynomial addendum) {
    Polynomial result;
    this->coefArray.size() > addendum.coefArray.size() ?
    result.init(*this, this->coefArray.size()) :
    result.init(*this, addendum.coefArray.size());
    for (int i = 0; i < addendum.coefArray.size(); ++i)
        result.coefArray[i + result.coefArray.size() - addendum.coefArray.size()] += addendum.coefArray[i];
    result.refactor();
    return result;
}

void Polynomial::operator += (const Polynomial addendum) {
    this->coefArray.size() > addendum.coefArray.size() ?
    this->init(*this, this->coefArray.size()) :
    this->init(*this, addendum.coefArray.size());
    for (int i = 0; i < addendum.coefArray.size(); ++i)
        this->coefArray[i + this->coefArray.size() - addendum.coefArray.size()] =
                this->coefArray[i + this->coefArray.size() - addendum.coefArray.size()] + addendum.coefArray[i];
    this->refactor();
    return;
}