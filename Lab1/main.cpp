#include <iostream>
#include "cmake-build-debug/Polynomial.h"

using namespace std;

int main() {
    double m_coefArray[] = { 2, 0, -7 };
    double coefArray[] = {1, 3, -7, 12};
    double coef[] = {0.5, 1.5};
    Polynomial one(2, m_coefArray);
    Polynomial two (3, coefArray);
    Polynomial four (1, coef);
    Polynomial three = two - one;
    three =  two / one;
    //three -= two;
    three /= four;
    cout << three(1);
    return 0;
}