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
#include "limits"
#include "iomanip"

class ScalarConverter {
private:
    static void convert_int(std::string scalar);
    static void convert_float(std::string scalar);
    static void convert_double(const std::string& scalar);
    static void convert_char(std::string scalar);
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
public:
    ~ScalarConverter();

    static void convert(std::string);
};


#endif //CPP06_SCALARCONVERTER_HPP
