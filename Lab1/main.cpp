/*!
 * \file
 * \mainpage Polynomial
 * \authors Sergei Golovachenko
 * \version 0.1
 * \date 14/09/2020
 * \todo everything
 */
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Polynomial.h"

TEST_CASE() {
    SECTION("1") {
        vector<int> aCoefArray{1, 2, 3};
        Polynomial a(aCoefArray.size() - 1, aCoefArray);
        REQUIRE(aCoefArray.size() == a.getPolynomialSize());
    }SECTION("2") {
        vector<int> aCoefArray = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("3") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("4") {
        int aCoefArray[] = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("5") {
        double aCoefArray[] = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        bool flag = true;
        for (int i = 0; i < a.getPolynomialSize(); ++i)
            if (a.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("6") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial aCopy(a);
        bool flag = true;
        for (int i = 0; i < aCopy.getPolynomialSize(); ++i)
            if (aCopy.getCoef(i) != aCoefArray[i])
                flag = false;
        REQUIRE(flag);
    }SECTION("7") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a - b;
        REQUIRE(c.getPolynomialSize() == 0);
    }SECTION("8") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c;
        c = a - b;
        REQUIRE(c.getPolynomialSize() == 0);
    }SECTION("9") {
        vector<double> aCoefArray = {1.3, 2.009, 3.14};
        vector<double> bCoefArray = {1.3, 2.009, 3.14};
        Polynomial a(2, aCoefArray);
        Polynomial b(2, bCoefArray);
        Polynomial c = a;
        c -= b;
        REQUIRE(c.getPolynomialSize() == 0);
    }SECTION("10") {
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
    }SECTION("11") {
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
    }SECTION("12") {
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
    }SECTION("13") {
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
    }SECTION("14") {
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
    }SECTION("15") {
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
    }SECTION("16") {
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
    }SECTION("17") {
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
    }SECTION("18") {
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
    }SECTION("19") {
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
    }SECTION("20") {
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
    }SECTION("21") {
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
    }SECTION("22") {
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
    }SECTION("23") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a(1) == 19);
    }SECTION("24") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a(0) == -3);
    }SECTION("25") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a[1] == 10);
    }SECTION("26") {
        vector<double> aCoefArray = {12, 10, -3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a[0] == -3);
    }SECTION("27") {
        vector<double> aCoefArray = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a.getCoef(2) == 3);
    }SECTION("28") {
        vector<double> aCoefArray = {1, 2, 3};
        Polynomial a(2, aCoefArray);
        REQUIRE(a.getPolynomialSize() == 3);
    }SECTION("29") {
        vector<double> aCoefArray = {1, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c(a);
        c *= b;
        REQUIRE(c.getPolynomialSize() == 3);
    }SECTION("30") {
        vector<double> aCoefArray = {1, 0};
        vector<double> bCoefArray = {2, 4};
        Polynomial a(1, aCoefArray);
        Polynomial b(1, bCoefArray);
        Polynomial c = a * b;
        REQUIRE(c.getCoef(1) == 4);
    }
}