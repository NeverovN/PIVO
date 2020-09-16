//
// Created by cirkul on 12.09.2020.
//

/*!
 * \file
 * \brief Приватный метод преобразования объекта класса
 *
 * Приватный метод преобразования объекта класса, удаляющий незначащие нули из массива коэффициентов
 */

#include "Polynomial.h"
/*!
 * Отсекает незначащие нули
 * @return Обновленны объект класса
 */
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