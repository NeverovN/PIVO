//
// Created by cirkul on 14.09.2020.
//

/*!
 * \file
 * \brief Перегруженные методы + и +=
 *
 * Перегруженные методы + и +=, которые дают возможность складывать объекты класса друг с другом
 * В каждом из методов создается объект класса result, который будет хранить в себе ответ,
 * после чего начинается сложение членов многочлена, имеющих одинаковую степень.
 *
 * Оператор + возвращает объект класса, т.к. вызывается не для указателя this, а для одного из слогаемых.
 *
 * Оператор += же изменяет сам объект, для которого был вызван, поэтому у него нет возвращаемого значения.
 */

#include "Polynomial.h"
/*!
 * Находит сумму двух объектов класса
 * @param addendum Второе слагаемое
 * @return Сумму объекта, для которого вызван метод, и переданного параметра
 */
Polynomial Polynomial::operator + (const Polynomial addendum) {
    Polynomial result;
    this->coefArray.size() > addendum.coefArray.size() ?
    result.init(*this, this->coefArray.size()) :
    result.init(*this, addendum.coefArray.size());
    for (int i = 0; i < addendum.coefArray.size(); ++i)
        result.coefArray[i + result.coefArray.size() - addendum.coefArray.size()] += addendum.coefArray[i];
    result.refactor();
    return result;
}
/*!
 * Находит сумму двух объектов класса
 * @param addendum Второе слагаемое
 */
void Polynomial::operator += (const Polynomial addendum) {
    this->coefArray.size() > addendum.coefArray.size() ?
    this->init(*this, this->coefArray.size()) :
    this->init(*this, addendum.coefArray.size());
    for (int i = 0; i < addendum.coefArray.size(); ++i)
        this->coefArray[i + this->coefArray.size() - addendum.coefArray.size()] =
                this->coefArray[i + this->coefArray.size() - addendum.coefArray.size()] + addendum.coefArray[i];
    this->refactor();
    return;
}