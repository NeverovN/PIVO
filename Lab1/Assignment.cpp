//
// Created by cirkul on 09.09.2020.
//

/*!
 * \file
 * \brief Перегруженый оператор ()
 *
 * Перегруженный оператор (), позволяющий вычислить значение исхоного многочлена при заданном аргументе
 *
 * Получает в качестве аргумента число (тип double), после чего
 * подставляет его в качестве аргумента с соответствующей степенью каждому члену многочлена.
 * С учетом знаков и величины коэффициентов происходит подсчет ответа, результат записывается
 * в переменную result и возвращается директивой return (возвращаемый тип double)
 */

#include <cmath>
#include "Polynomial.h"
/*!
 * Находит значение многочлена при заданном значении аргумента
 * @param argument Значение аргумента
 * @return Значение многочлена
 */
double Polynomial::operator()(const double argument) {
    double result = 0;
    for (int i = 0; i < this->coefArray.size(); ++i)
        result += this->coefArray[i]*pow(argument, this->coefArray.size() - i - 1);
    return result;
}