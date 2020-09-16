/*!
 * \file
 * \mainpage Polynomial
 * \authors Sergei Golovachenko
 * \version 0.1
 * \date 14/09/2020
 * \todo everything
 */

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    double m_coefArray[] = {1, 3, 0, -7};
    double coefArray[] = {1, 3, -7, 12};
    double coef[] = {0.5, 1.5};
    Polynomial one(3, m_coefArray);
    Polynomial two(3, coefArray);
    Polynomial four(1, coef);
    Polynomial three = two - one;
    cout << "one[1] = " << one[1];
    return 0;
}