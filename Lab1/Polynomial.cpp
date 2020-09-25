//
// Created by cirkul on 25.09.2020.
//

#include "Polynomial.h"
#include <cmath>
#include <iostream>

using namespace std;
/*!
 * \file
 */

/*!
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
 * Находит сумму двух объектов класса
 * @param addendum Второе слагаемое
 * @return Сумму объекта, для которого вызван метод, и переданного параметра
 */
Polynomial Polynomial::operator+(const Polynomial addendum) {
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
void Polynomial::operator+=(const Polynomial addendum) {
    this->coefArray.size() > addendum.coefArray.size() ?
    this->init(*this, this->coefArray.size()) :
    this->init(*this, addendum.coefArray.size());
    for (int i = 0; i < addendum.coefArray.size(); ++i)
        this->coefArray[i + this->coefArray.size() - addendum.coefArray.size()] =
                this->coefArray[i + this->coefArray.size() - addendum.coefArray.size()] + addendum.coefArray[i];
    this->refactor();
}

/*!
 * \brief Перегруженый оператор ()
 *
 * Перегруженный оператор (), позволяющий вычислить значение исхоного многочлена при заданном аргументе
 *
 * Получает в качестве аргумента число (тип double), после чего
 * подставляет его в качестве аргумента с соответствующей степенью каждому члену многочлена.
 * С учетом знаков и величины коэффициентов происходит подсчет ответа, результат записывается
 * в переменную result и возвращается директивой return (возвращаемый тип double)
 */


/*!
 * Находит значение многочлена при заданном значении аргумента
 * @param argument Значение аргумента
 * @return Значение многочлена
 */
double Polynomial::operator()(const double argument) {
    double result = 0;
    for (int i = 0; i < this->coefArray.size(); ++i)
        result += this->coefArray[i] * pow(argument, this->coefArray.size() - i - 1);
    return result;
}


/*!
 * \brief Конструкторы для инициализации объектов класса сразу при создании
 */

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



/*!
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

/*!
 * Находит частное двух многочленов
 * @param divider Делитель
 * @return Частное объекта, для которого вызван метод, и переданного параметра
 */
Polynomial Polynomial::operator/(const Polynomial divider) {
    Polynomial result;


    if (this->coefArray.size() < divider.coefArray.size())
        throw "Invalid data: dividend is less than divider";


    result.coefArray.resize(this->coefArray.size() - divider.coefArray.size() + 1);

    result.division(*this, divider);

    return result;
}

/*!
 * Находит частное двух многочленов
 * @param divider Делитель
 */
void Polynomial::operator/=(const Polynomial divider) {
    Polynomial result;

    if (this->coefArray.size() < divider.coefArray.size())
        throw "Invalid data: dividend is less than divider";


    result.coefArray.resize(this->coefArray.size() - divider.coefArray.size() + 1);

    result.division(*this, divider);
    *this = result;
    this->refactor();
}

/*!
 * \file
 * \brief Метод получения коэффициента по заданному индексу
 *
 * Позволяет получить коэффициент многочлена по заданному индексу.
 */

/*!
 * Возвращает коэффициент по заданному индексу
 * @param index Индекс коэффициета
 * @return Искомый коэффициент
 */
double Polynomial::getCoef(int index) { return this->coefArray[index]; }


/*!
 * \brief Метод получения количества членов многочлена
 *
 * Позволяет получить количество членов в исходном многочлене, включая свободный член
 */

/*!
 * Возвращает количество членов многочлена
 * @return Количество членов, включая свободный
 */
int Polynomial::getPolynomialSize() { return this->coefArray.size(); }

/*!
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

/*!
 * \brief Перегруженные методы * и *=
 *
 * Перегруженные методы * и *=, которые дают возможность умножать объекты класса друг на друга
 * В каждом из методов создается объект класса result, который будет хранить в себе ответ,
 * после чего начинается перемножение каждого из членов 1-го многочлена на каждый из членов 2-го многочлена.
 *
 * Оператор * возвращает объект класса, т.к. вызывается не для указателя this, а для одного из множителей.
 *
 * Оператор *= же изменяет сам объект, для которого был вызван, поэтому у него нет возвращаемого значения.
 */

/*!
 * Находит произведение двух объектов класса
 * @param multiplier Второй множитель
 * @return Произведение объекта, для которого вызван метод, и переданного параметра
 */
Polynomial Polynomial::operator*(const Polynomial multiplier) {
    Polynomial result;
    result.coefArray.resize(this->coefArray.size() + multiplier.coefArray.size() - 1);
    for (int i = 0; i < this->coefArray.size(); i++) {
        for (int j = 0; j < multiplier.coefArray.size(); j++) {
            result.coefArray[i + j] += this->coefArray[i] * multiplier.coefArray[j];
        }
    }
    return result;
}

/*!
 * Находит произведение двух объектов класса
 * @param multiplier Второй множитель
 */
void Polynomial::operator*=(const Polynomial multiplier) {
    Polynomial result;
    result.coefArray.resize(this->coefArray.size() + multiplier.coefArray.size() - 1);
    for (int i = 0; i < this->coefArray.size(); i++) {
        for (int j = 0; j < multiplier.coefArray.size(); j++) {
            result.coefArray[i + j] += this->coefArray[i] * multiplier.coefArray[j];
        }
    }
    *this = result;
}

/*!
 * \brief перегруженный оператор вывода
 *
 * Перешруженный оператор вывода, позволяющий вывести на экран многочлен в стандартном виде.
 * Оператор игнорирует незначащие символы наподобие 0*х, x^1, x^0, +/-0, и знак * как таковой в принципе.
 * Также оператор игнорирует незначащий + в начале многочлена, если таковой имеется.
 */


ostream &operator<<(ostream &out, const Polynomial &output) {
    if (!output.coefArray.empty()) {
        for (int i = 0; i < output.coefArray.size(); ++i) {
            if (output.coefArray[i] == 0) {
                continue;
            }
            if (output.coefArray[i] >= 0 && i != 0) {
                out << "+";
            }
            out << output.coefArray[i];
            if (i < output.coefArray.size() - 1) {
                out << "x";
                if (i < output.coefArray.size() - 2) {
                    out << "^" << output.coefArray.size() - 1 - i;
                }
            }
        }
    }
    return out;
}



/*!
 * \brief Приватный метод преобразования объекта класса
 *
 * Приватный метод преобразования объекта класса, удаляющий незначащие нули из массива коэффициентов
 */

/*!
 * Отсекает незначащие нули
 * @return Обновленны объект класса
 */
Polynomial Polynomial::refactor() {
    int count = 0;
    while (this->coefArray[0] == 0) {
        for (int i = 0; i < this->coefArray.size(); ++i)
            this->coefArray[i] = this->coefArray[i + 1];
        count++;
    }
    for (int i = 0; i < count; ++i)
        this->coefArray.pop_back();
    return *this;
}

/*!
 * \brief Перегруженный метод []
 *
 * Перегруженный метод [], который дает возможность находить значение каждого коэффициента многочлена
 *
 * Оператор [] возвращает значение переменной в массиве coefArray нужного класса.
 */

/*!
 * Находит коэффициент нужного члена
 * @param requiredIndex Показатель степени члена, коэффициент которого пользователь желает найти
 * @return Коэффициент при заданном члене многочлена
 */
double Polynomial::operator[](const int requiredIndex) {
    return this->coefArray[this->coefArray.size() - requiredIndex - 1];
}

/*!
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


/*!
 * Вычисляет разность двух многочленов
 * @param subtrahend вычитаемое
 * @return Результат вычитания
 */
Polynomial Polynomial::operator-(const Polynomial subtrahend) {
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
void Polynomial::operator-=(const Polynomial subtrahend) {
    this->coefArray.size() > subtrahend.coefArray.size() ?
    this->init(*this, this->coefArray.size()) :
    this->init(*this, subtrahend.coefArray.size());
    for (int i = 0; i < subtrahend.coefArray.size(); ++i)
        this->coefArray[i + this->coefArray.size() - subtrahend.coefArray.size()] =
                this->coefArray[i + this->coefArray.size() - subtrahend.coefArray.size()] - subtrahend.coefArray[i];
    this->refactor();
}

void Polynomial::division(Polynomial devidende, Polynomial divider) {
    for (int i = 0; i < this->coefArray.size(); ++i) {
        Polynomial buff;
        this->coefArray[i] = devidende.coefArray[0] / divider.coefArray[0];
        buff.coefArray.resize(devidende.coefArray.size());
        for (int j = 0; j < divider.coefArray.size(); ++j)
            buff.coefArray[j] = this->coefArray[i] * divider.coefArray[j];
        for (int j = 0; j < devidende.coefArray.size(); ++j)
            devidende.coefArray[j] -= buff.coefArray[j];
        for (int j = 0; j < devidende.coefArray.size() - 1; ++j)
            devidende.coefArray[j] = devidende.coefArray[j + 1];
        devidende.coefArray.pop_back();
    }
}
