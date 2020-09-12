//
// Created by cirkul on 12.09.2020.
//

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
}

/*ostream &operator<<(ostream &out, const Polynomial &output) {
    if (!output.coefArray.empty()) {
        if (output.coefArray.size() > 2) {
            if (output.coefArray[0] != 1)
                cout << output.coefArray[0];
            cout << "x^" << output.coefArray.size() - 1;
        } else if (output.coefArray.size() == 2) {
            if (output.coefArray[0] != 1)
                cout << output.coefArray[0];
            cout << "x";
        } else if (output.coefArray.size() == 1)
            if (output.coefArray[0] != 1)
                cout << output.coefArray[0];
        for (int i = 1; i < output.coefArray.size() - 2; ++i) {
            if (output.coefArray[i] != 0)
                if (output.coefArray[i] > 0)
                    cout << "+" << output.coefArray[i] << "x^" << output.coefArray.size() - i - 1;
                else
                    cout << output.coefArray[i] << "x^" << output.coefArray.size() - i - 1;

        }
        //if (output.coefArray.size() > 2)
            if (output.coefArray[output.coefArray.size() - 2] != 0)
                if (output.coefArray[output.coefArray.size() - 2] > 0)
                    cout << "+" << output.coefArray[output.coefArray.size() - 2] << "x";
                else
                    cout << output.coefArray[output.coefArray.size() - 2] << "x";

        if (output.coefArray.size() > 1)
            if (output.coefArray[output.coefArray.size() - 1] != 0)
                if (output.coefArray[output.coefArray.size() - 1] > 0)
                    cout << "+" << output.coefArray[output.coefArray.size() - 1];
                else
                    cout << output.coefArray[output.coefArray.size() - 1];

    }
}*/