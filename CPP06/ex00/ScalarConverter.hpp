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

class ScalarConverter {
private:
    void convert_int(std::string scalar);
    void convert_float(std::string scalar);
    double convert_double(std::string scalar);
    void convert_char(std::string scalar);
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const &src);
    ~ScalarConverter();

    void convert(std::string);
};


#endif //CPP06_SCALARCONVERTER_HPP
