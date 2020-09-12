//
// Created by cirkul on 09.09.2020.
//

#include "Polynomial.h"

Polynomial::Polynomial() {}

Polynomial::Polynomial(const int m_power, const double m_coefArray[]) {
    this->coefArray.resize(m_power + 1);
    for (int i = 0; i < this->coefArray.size(); i++)
        coefArray[i] = m_coefArray[i];
}