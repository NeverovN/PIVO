//
// Created by cirkul on 09.09.2020.
//

/**
 *      \file
 *      \brief Заголовочный файл с описанием класса многочлен
 *
 *     Класс содержит в себе лишь одно поле: вектор коэффициентов при соответствующих степенях многочленаЮ
 *     Также в классе описаны такие методы, как перегруженные операторы +, +=, -, -=, *, *=, /, /=, [], ().
 *     Существует конструктор по умолчанию и конструктор с параметрами, а также приватный метод init, который позволяет заполнить
 *     пустой элемент класса заданными элементами.
 */

#ifndef UNTITLED2_POLYNOMIAL_H
#define UNTITLED2_POLYNOMIAL_H

#endif //UNTITLED2_POLYNOMIAL_H

#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
    vector<double> coefArray;
    void init(Polynomial value, int power);
    Polynomial refactor();
public:
    Polynomial();
    Polynomial(const int power, const double coefArray[]);
    double operator () (const double argument);
    Polynomial operator -= (const Polynomial subtrahend);
    Polynomial operator - (const Polynomial subtrahend);
    Polynomial operator / (const Polynomial divider);
    Polynomial operator /= (const Polynomial divider);
    friend ostream& operator << (ostream &out, const Polynomial &point);
    double operator [] (const int receivedIndex);
    Polynomial operator + (const Polynomial addendum);
    Polynomial operator += (const Polynomial addendum);
    Polynomial operator * (const Polynomial multiplier);
    Polynomial operator *= (const Polynomial multiplier);
};
