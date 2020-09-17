//
// Created by cirkul on 18.09.2020.
//

/*!
 * \file
 * \brief Метод получения коэффициента по заданному индексу
 *
 * Позволяет получить коэффициент многочлена по заданному индексу.
 */

#include "Polynomial.h"
#include <vector>
/*!
 * Возвращает коэффициент по заданному индексу
 * @param index Индекс коэффициета
 * @return Искомый коэффициент
 */
double Polynomial::getCoef(int index) { return this->coefArray[index]; }