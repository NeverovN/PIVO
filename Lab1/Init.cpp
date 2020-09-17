//
// Created by cirkul on 09.09.2020.
//

/*!
 * \file
 * \brief Приватный метод, инициализирующий объект класса
 *
 * Приватный метод, инициализирующий объект класса с учетом необходимых параметров.
 *
 * В качестве аргументов передается другой объект класса и переменная типа int,
 * содержащая размер будущего массива. Сам же метод заполняет массив элементов объекта,
 * для которого он вызван, значениями из массива коэффициентов объекта, переданного в качестве
 * параметра. При этом, при необъодимости, некоторое количество коэффициентов в начале
 * могут быть инициализированы нулями
 */

#include "Polynomial.h"
/*!
 * Инициализирует объект класса
 * @param value Объект класса для копирования
 * @param power Размер массива коэффициентов
 */
void Polynomial::init(Polynomial value, int power) {
    this->coefArray.clear();
    this->coefArray.resize(power);
    for (int i = this->coefArray.size() - 1; i >= 0; --i) {
        if (i >= this->coefArray.size() - value.coefArray.size())
            this->coefArray[i] = value.coefArray[i - this->coefArray.size() + value.coefArray.size()];
        else
            this->coefArray[i] = 0;
    }
}