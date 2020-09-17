//
// Created by cirkul on 12.09.2020.
//

/*!
 * \file
 * \brief Перегруженный метод []
 *
 * Перегруженный метод [], который дает возможность находить значение каждого коэффициента многочлена 
 *
 * Оператор [] возвращает значение переменной в массиве coefArray нужного класса.
 */

#include "Polynomial.h"
/*!
 * Находит коэффициент нужного члена
 * @param requiredIndex Показатель степени члена, коэффициент которого пользователь желает найти
 * @return Коэффициент при заданном члене многочлена
 */
double Polynomial::operator[](const int requiredIndex) {
    return this->coefArray[this->coefArray.size() - requiredIndex - 1];
}
