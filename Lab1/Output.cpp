//
// Created by cirkul on 12.09.2020.
//

/*!
 * \file
 * \brief перегруженный оператор вывода
 *
 * Перешруженный оператор вывода, позволяющий вывести на экран многочлен в стандартном виде.
 * Оператор игнорирует незначащие символы наподобие 0*х, x^1, x^0, +/-0, и знак * как таковой в принципе.
 * Также оператор игнорирует незначащий + в начале многочлена, если таковой имеется.
 */

#include "Polynomial.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &out, const Polynomial &output) {
    if (!output.coefArray.empty()) {
        for (int i = 0; i < output.coefArray.size(); ++i) {
            if (output.coefArray[i] == 0) {
                continue;
            }
            if (output.coefArray[i] >= 0 && i != 0) {
                out << "+";
            }
            out << output.coefArray[i];
            if (i < output.coefArray.size() - 1) {
                out << "x";
                if (i < output.coefArray.size() - 2) {
                    out << "^" << output.coefArray.size() - 1 - i;
                }
            }
        }
    }
    return out;
}