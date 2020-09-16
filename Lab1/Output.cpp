//
// Created by cirkul on 12.09.2020.
//

/*!
 * \file
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