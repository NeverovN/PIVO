//
// Created by cirkul on 12.09.2020.
//

#include "Polynomial.h"

Polynomial Polynomial::refactor() {
    int count = 0;
    while (this->coefArray[0] == 0){
        for (int i = 0; i < this->coefArray.size(); ++i)
            this->coefArray[i] = this->coefArray[i+1];
        count++;
    }
    for (int i = 0; i < count; ++i)
        this->coefArray.pop_back();
    return *this;
}