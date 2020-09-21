/*!
 * \file
 * \mainpage Polynomial
 * \authors Torop Nikita & Sergei Golovachenko
 * \version 0.1
 * \date 14/09/2020
 * \todo everything
 */
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Polynomial.h"

TEST_CASE() {
    SECTION("polynomial size") {
        vector<int> aCoefArray{1, 2, 3};
        Polynomial a(aCoefArray.size() - 1, aCoefArray);
        REQUIRE(aCoefArray.size() == a.getPolynomialSize());
    }SECTION("vector<int> correct coefs") {
        vector<int> aCoefArray = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("vector<double> correct coefs") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("int arr correct coefs") {
        int aCoefArray[] = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("double arr correct coefs") {
        double aCoefArray[] = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("correct copy constructor") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial aCopy(a);
        bool flag = true;
        for (int i = 0; i < aCopy.getPolynomialSize(); ++i)
            if (aCopy.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("equal subtraction + var declaration") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a - b;
        REQUIRE(c.getPolynomialSize() == 0);
    }SECTION("equal substruction") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c;
        c = a - b;
        REQUIRE(c.getPolynomialSize() == 0);
    }SECTION("equal subtraction by -=") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a;
        c -= b;
        REQUIRE(c.getPolynomialSize() == 0);
    }SECTION("subtract the smaller from the larger") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a - b;
        bool flag = true;
        if (c.getPolynomialSize() != 2)
            flag = false;
        if (c.getCoef(0) != aCoefArray[1] - bCoefArray[1] || c.getCoef(1) != 0)
            flag = false;
        REQUIRE(flag);
    }SECTION("subtract the larger from the smaller") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = b - a;
        bool flag = true;
        if (c.getPolynomialSize() != 2)
            flag = false;
        if (c.getCoef(0) != bCoefArray[1] - aCoefArray[1] || c.getCoef(1) != 0)
            flag = false;
        REQUIRE(flag);
    }SECTION("adding equals") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a + b;
        bool flag = true;
        if (c.getPolynomialSize() != 3)
            flag = false;
        for (int i = 0; i < c.getPolynomialSize(); ++i) {
            if (c.getCoef(i) != aCoefArray[i] + bCoefArray[i])
                flag = false;
        }
        REQUIRE(flag);
    }SECTION("adding different degrees") {
        vector<double> aCoefArray = {-4, 1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(3, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a + b;
        bool flag = true;
        if (c.getPolynomialSize() != 4)
            flag = false;
        if (c.getCoef(0) != -4)
            flag = false;
        for (int i = 0; i < c.getPolynomialSize() - 1; ++i)
            if (c.getCoef(i + 1) != aCoefArray[i + 1] + bCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("inverted adding different degrees") {
        vector<double> aCoefArray = {-4, 1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(3, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = b + a;
        bool flag = true;
        if (c.getPolynomialSize() != 4)
            flag = false;
        if (c.getCoef(0) != -4)
            flag = false;
        for (int i = 0; i < c.getPolynomialSize() - 1; ++i)
            if (c.getCoef(i + 1) != aCoefArray[i + 1] + bCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("adding different degrees with +=") {
        vector<double> aCoefArray = {-4, 1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(3, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c(a);
        c += b;
        bool flag = true;
        if (c.getPolynomialSize() != 4)
            flag = false;
        if (c.getCoef(0) != -4)
            flag = false;
        for (int i = 0; i < c.getPolynomialSize() - 1; ++i)
            if (c.getCoef(i + 1) != aCoefArray[i + 1] + bCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("multiplication + var declaration") {
        vector<double> aCoefArray = {-1, 3};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = a * b;
        bool flag = true;
        if (c.getPolynomialSize() != 3)
            flag = false;
        if (c.getCoef(0) != -2)
            flag = false;
        if (c.getCoef(1) != 2)
            flag = false;
        if (c.getCoef(2) != 12)
            flag = false;
        REQUIRE(flag);
    }SECTION("inverted multiplication + var declaration") {
        vector<double> aCoefArray = {-1, 3};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = b * a;
        bool flag = true;
        if (c.getPolynomialSize() != 3)
            flag = false;
        if (c.getCoef(0) != -2)
            flag = false;
        if (c.getCoef(1) != 2)
            flag = false;
        if (c.getCoef(2) != 12)
            flag = false;
        REQUIRE(flag);
    }SECTION("multiplication with zero member") {
        vector<double> aCoefArray = {1, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = a * b;
        bool flag = true;
        if (c.getPolynomialSize() != 3)
            flag = false;
        if (c.getCoef(0) != 2)
            flag = false;
        if (c.getCoef(1) != 4)
            flag = false;
        if (c.getCoef(2) != 0)
            flag = false;
        REQUIRE(flag);
    }SECTION("multiplication with *=") {
        vector<double> aCoefArray = {1, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c(a);
        c *= b;
        bool flag = true;
        if (c.getPolynomialSize() != 3)
            flag = false;
        if (c.getCoef(0) != 2)
            flag = false;
        if (c.getCoef(1) != 4)
            flag = false;
        if (c.getCoef(2) != 0)
            flag = false;
        REQUIRE(flag);
    }SECTION("division + var declaration") {
        vector<double> aCoefArray = {1, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = a / b;
        bool flag = true;
        if (c.getPolynomialSize() != 1)
            flag = false;
        if (c.getCoef(0) != 0.5)
            flag = false;
        REQUIRE(flag);
    }SECTION("dividing with /= and copy constructor") {
        vector<double> aCoefArray = {12, 10, -3};
        vector<double> bCoefArray = {3, 1};
        Polynomial a(2, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c(a);
        c /= b;
        bool flag = true;
        if (c.getPolynomialSize() != 2)
            flag = false;
        if (c.getCoef(0) != 4)
            flag = false;
        if (c.getCoef(1) != 2)
            flag = false;
        REQUIRE(flag);
    }SECTION("dividing more by less + var declaration") {
        vector<double> aCoefArray = {12, 10, -3};
        vector<double> bCoefArray = {3, 1};
        Polynomial a(2, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = a / b;
        bool flag = true;
        if (c.getPolynomialSize() != 2)
            flag = false;
        if (c.getCoef(0) != 4)
            flag = false;
        if (c.getCoef(1) != 2)
            flag = false;
        REQUIRE(flag);
    }SECTION("dividing equals with /= and copy constructor") {
        vector<double> aCoefArray = {12, 10, -3};
        vector<double> bCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c(a);
        c /= b;
        bool flag = true;
        if (c.getPolynomialSize() != 1)
            flag = false;
        if (c.getCoef(0) != 1)
            flag = false;
        REQUIRE(flag);
    }SECTION("calculating the value of a polynomial at a point 1") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a(1) == 19);
    }SECTION("calculating the value of a polynomial at a point 0") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a(0) == -3);
    }SECTION("coefficient of a polynomial by degree 1") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a[1] == 10);
    }SECTION("26") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a[0] == -3);
    }SECTION("coefficient of a polynomial by index 2") {
        vector<double> aCoefArray = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a.getCoef(2) == 3);
    }SECTION("size of polynomial") {
        vector<double> aCoefArray = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a.getPolynomialSize() == 3);
    }SECTION("multiplication + copy constructor") {
        vector<double> aCoefArray = {1, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c(a);
        c *= b;
        REQUIRE(c.getPolynomialSize() == 3);
    }SECTION("division error") {
        vector<double> aCoefArray = {0, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = a / b;
        REQUIRE(1);
    }
}