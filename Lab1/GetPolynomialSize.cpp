//
// Created by cirkul on 18.09.2020.
//

/*!
 * \file
 * \brief Метод получения количества членов многочлена
 *
 * Позволяет получить количество членов в исходном многочлене, включая свободный член
 */

#include "Polynomial.h"
/*!
 * Возвращает количество членов многочлена
 * @return Количество членов, включая свободный
 */
int Polynomial::getPolynomialSize() { return this->coefArray.size(); }