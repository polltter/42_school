//
// Created by miguel on 30-06-2023.
//

#ifndef CPP06_SCALARCONVERTER_HPP
#define CPP06_SCALARCONVERTER_HPP

#include "string"
#include "iostream"
#include "cstdlib"
#include <sstream>
#include <cmath>
#include "climits"
#include <cfloat>

enum tipos {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConverter {
private:
    static char c;
    static int  i;
    static float f;
    static double d;
    static bool checkInt(const std::string&);
    static bool checkDouble(const std::string&);
    static bool checkFloat(const std::string&);
    static void toChar(const std::string&);
    static void toInt(const std::string&);
    static void toFloat(const std::string&);
    static void toDouble(const std::string&);
    static void display(const std::string& s);
    static int typeOfNumber(const std::string&);
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &scalarConverter);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &scalarConverter);
    static void converter(const std::string& s);
};


#endif //CPP06_SCALARCONVERTER_HPP
