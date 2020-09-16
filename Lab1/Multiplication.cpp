//
// Created by cirkul on 14.09.2020.
//

/*!
 * \file
 * \brief Перегруженные методы * и *=
 *
 * Перегруженные методы * и *=, которые дают возможность умножать объекты класса друг на друга
 * В каждом из методов создается объект класса result, который будет хранить в себе ответ,
 * после чего начинается перемножение каждого из членов 1-го многочлена на каждый из членов 2-го многочлена.
 *
 * Оператор * возвращает объект класса, т.к. вызывается не для указателя this, а для одного из множителей.
 *
 * Оператор *= же изменяет сам объект, для которого был вызван, поэтому у него нет возвращаемого значения.
 */

#include "Polynomial.h"
/*!
 * Находит произведение двух объектов класса
 * @param multiplier Второй множитель
 * @return Произведение объекта, для которого вызван метод, и переданного параметра
 */
Polynomial Polynomial::operator * (const Polynomial multiplier) {
    Polynomial result;
    result.coefArray.resize(this->coefArray.size() + multiplier.coefArray.size() - 1);
    for (int i = 0; i < this->coefArray.size(); i++) {
        for (int j = 0; j < multiplier.coefArray.size(); j++) {
            result.coefArray[i + j] += this->coefArray[i] * multiplier.coefArray[j];
        }
    }
    return result;
}
/*!
 * Находит произведение двух объектов класса
 * @param multiplier Второй множитель
 */
void Polynomial::operator *= (const Polynomial multiplier) {
    Polynomial result;
    result.coefArray.resize(this->coefArray.size() + multiplier.coefArray.size() - 1);
    for (int i = 0; i < this->coefArray.size(); i++) {
        for (int j = 0; j < multiplier.coefArray.size(); j++) {
            result.coefArray[i + j] += this->coefArray[i] * multiplier.coefArray[j];
        }
    }
    *this = result;
}
