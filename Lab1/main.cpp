/*!
 * \author Sergei Golovachenko
 */

#include <iostream>
#include "cmake-build-debug/Polynomial.h"

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