#include "Polynomial.h"

double Polynomial::operator[](const int receivedIndex) {
    double requiredCoef = 0;
    requiredCoef = this->coefArray[receivedIndex-1];
    return requiredCoef;
}