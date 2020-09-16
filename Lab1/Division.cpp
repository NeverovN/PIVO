//
// Created by cirkul on 09.09.2020.
//

/*!
 * \file
 * \brief Перегруженные операторы / и /=
 *
 * Перегруженные операторы / и /= , позволяющие производить операцию деления многочлена на многочлен.
 *
 * Деление многочлена младшей степени на многочлен старшей считается ошибкой, встречая которую компилятор
 * завершает выполнение программы и выводит ошибку.
 *
 * Принцип деления такой же, как и при делении многочленов в столбик. В переменную result помещается
 * результат деления. Переменная buff содержит в себе промежуточные результаты деленияю
 *
 * Оператор / возвращает объект класса, т.к. вызывается не для указателя this, а для делимого.
 *
 * Оператор /= же изменяет сам объект, для которого был вызван, поэтому у него нет возвращаемого значения.
 */

#include <iostream>
#include "Polynomial.h"

using namespace std;
/*!
 * Находит частное двух многочленов
 * @param divider Делитель
 * @return Частное объекта, для которого вызван метод, и переданного параметра
 */
Polynomial Polynomial::operator/(const Polynomial divider) {
    Polynomial result;

    try {
        if (this->coefArray.size() < divider.coefArray.size())
            throw "Invalid data: dividend is less than divider";
    }
    catch (const char *exception) {
        cout << "Division Error: " << exception <<endl;
        abort();
    }

    result.coefArray.resize(this->coefArray.size() - divider.coefArray.size() + 1);

    for (int i = 0; i < result.coefArray.size(); ++i) {
        Polynomial buff;
        result.coefArray[i] = this->coefArray[0] / divider.coefArray[0];
        buff.coefArray.resize(this->coefArray.size());
        for (int j = 0; j < divider.coefArray.size(); ++j) 
            buff.coefArray[j] = result.coefArray[i] * divider.coefArray[j];
        for (int j = 0; j < this->coefArray.size(); ++j)
            this->coefArray[j] -= buff.coefArray[j];
        for (int j = 0; j < this->coefArray.size() - 1; ++j)
            this->coefArray[j] = this->coefArray[j + 1];
        this->coefArray.pop_back();
    }

    return result;
}
/*!
 * Находит частное двух многочленов
 * @param divider Делитель
 */
void Polynomial::operator/=(const Polynomial divider) {
    Polynomial result;

    try {
        if (this->coefArray.size() < divider.coefArray.size())
            throw "Invalid data: dividend is less than divider";
    }
    catch (const char *exception) {
        cout << "Division Error: " << exception << endl;
        abort();
    }

    result.coefArray.resize(this->coefArray.size() - divider.coefArray.size() + 1);

    for (int i = 0; i < result.coefArray.size(); ++i) {
        Polynomial buff;
        result.coefArray[i] = this->coefArray[0] / divider.coefArray[0];
        buff.coefArray.resize(this->coefArray.size());
        for (int j = 0; j < divider.coefArray.size(); ++j) 
            buff.coefArray[j] = result.coefArray[i] * divider.coefArray[j];
        for (int j = 0; j < this->coefArray.size(); ++j)
            this->coefArray[j] -= buff.coefArray[j];
        for (int j = 0; j < this->coefArray.size() - 1; ++j)
            this->coefArray[j] = this->coefArray[j + 1];
        this->coefArray.pop_back();
    }
    *this = result;
    this->refactor();
    return;
}
