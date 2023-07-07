//
// Created by miguel on 30-06-2023.
//

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    (void)src;
    return *this;

}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string s) {
    double  doub = convert_double(s);
    int     i = static_cast<int>(doub);
    float   f = static_cast<float>(doub);
    char    c = static_cast<char>(doub);
    std::cout << "char: "<< c << std::endl;
    std::cout << "int: "<< i << std::endl;
    std::cout << "float: "<< f << std::endl;
    std::cout << "double: "<< doub << std::endl;

}


double ScalarConverter::convert_double(std::string scalar) {

    if (scalar == "nan" || scalar == "nanf")
        return nan("");
    else if (scalar == "+inf" || scalar == "+inff" )
        return std::numeric_limits<double>::infinity();
    else if (scalar == "-inf" || scalar == "-inff" )
        return std::numeric_limits<double>::infinity() * -1;
    else {
        std::stringstream ss(scalar);
        double value;
        ss >> value;
        return value;
    }
}

void ScalarConverter::convert_int(std::string scalar) {

}
