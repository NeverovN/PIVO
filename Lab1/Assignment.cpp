//
// Created by cirkul on 09.09.2020.
//

#include <cmath>
#include "Polynomial.h"

double Polynomial::operator()(const double argument) {
    double result = 0;
    for (int i = 0; i < this->coefArray.size(); ++i)
        result += this->coefArray[i]*pow(argument, this->coefArray.size() - i - 1);
    return result;
}