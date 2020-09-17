//
// Created by cirkul on 09.09.2020.
//

/*!
 * \file
 * \brief Конструкторы для инициализации объектов класса сразу при создании
 */

#include "Polynomial.h"
/*!
 * Конструктор по умолчанию. Вызывается при встрече строки кода вида Polynomial object; При этом поля объекта object остаются пустыми,
 * т.к. на инициализацию не поступило никаких данных.
 */
Polynomial::Polynomial() = default;
/*!
 * Конструктор, заполняющий массив коэффициентов объекта класса из переданного массива значений типа double
 * @param power Старшая степень многочлена
 * @param coefArray Массив значений
 */
Polynomial::Polynomial(const int power, const double coefArray[]) {
    this->coefArray.resize(power + 1);
    for (int i = 0; i < this->coefArray.size(); i++)
        this->coefArray[i] = coefArray[i];
    this->refactor();
}
/*!
 * Конструктор, заполняющий массив коэффициентов объекта класса из переданного массива значений типа int
 * @param power Старшая степень многочлена
 * @param coefArray Массив значений
 */
Polynomial::Polynomial(const int power, const int coefArray[]) {
    this->coefArray.resize(power + 1);
    for (int i = 0; i < this->coefArray.size(); i++)
        this->coefArray[i] = coefArray[i];
    this->refactor();
}
/*!
 * Конструктор, заполняющий массив коэффициентов объекта класса из переданного вектора типа double
 * @param power Старшая степень многочлена
 * @param coefArray Массив значений
 */
Polynomial::Polynomial(const int power, const vector<double> coefArray) {
    this->coefArray.resize(power + 1);
    for (int i = 0; i < this->coefArray.size(); i++)
        this->coefArray[i] = coefArray[i];
    this->refactor();
}
/*!
 * Конструктор, заполняющий массив коэффициентов объекта класса из переданного вектора типа int
 * @param power Старшая степень многочлена
 * @param coefArray Массив значений
 */
Polynomial::Polynomial(const int power, const vector<int> coefArray) {
    this->coefArray.resize(power + 1);
    for (int i = 0; i < this->coefArray.size(); i++)
        this->coefArray[i] = coefArray[i];
    this->refactor();
}

