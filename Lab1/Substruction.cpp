//
// Created by cirkul on 09.09.2020.
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

/*!
 * \file
 * \brief Перегруженные методы - и -=
 *
 * Перегруженные методы - и -=, позволяющие вычислять разность двух многочленов.
 * В каждом из методов создается объект класса result, который будет хранить в себе ответ,
 * после чего начинается вычитание соответствующих членов вычитаемого из членов уменьшаемого.
 *
 * Оператор - возвращает объект класса, т.к. вызывается не для указателя this, а для уменьшаемого.
 *
 * Оператор -= же изменяет сам объект, для которого был вызван, поэтому у него нет возвращаемого значения.
 */

#include "Polynomial.h"
using namespace std;
/*!
 * Вычисляет разность двух многочленов
 * @param subtrahend вычитаемое
 * @return Результат вычитания
 */
Polynomial Polynomial::operator - (const Polynomial subtrahend){
    Polynomial result;
    this->coefArray.size() > subtrahend.coefArray.size() ?
    result.init(*this, this->coefArray.size()) :
    result.init(*this, subtrahend.coefArray.size());
    for (int i = 0; i < subtrahend.coefArray.size(); ++i)
        result.coefArray[i + result.coefArray.size() - subtrahend.coefArray.size()] -= subtrahend.coefArray[i];
    result.refactor();
    return result;
}
/*!
 * Вычисляет разность двух многочленов
 * @param subtrahend Вычитаемое
 */
void Polynomial::operator -= (const Polynomial subtrahend){
    this->coefArray.size() > subtrahend.coefArray.size() ?
    this->init(*this, this->coefArray.size()) :
    this->init(*this, subtrahend.coefArray.size());
    for (int i = 0; i < subtrahend.coefArray.size(); ++i)
        this->coefArray[i + this->coefArray.size() - subtrahend.coefArray.size()] =
                this->coefArray[i + this->coefArray.size() - subtrahend.coefArray.size()] - subtrahend.coefArray[i];
    this->refactor();
    return;
}
