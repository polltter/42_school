//
// Created by miguel on 30-06-2023.
//

#include "ScalarConverter.hpp"

int containsOnly(std::string &s, std::string chars) {
    return (s.find_first_not_of(chars) == std::string::npos);
}

int containsOnlyOneOf(std::string &s, char c) {
    return (s.find_first_of(c) == s.find_last_of(c));
}

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
    if (s.empty())
        return;
    if (s.length() == 1 && !isdigit(s[0])) {
        convert_char(s);
    }
    std::string s2;
    if (s[0] == '-' || s[0] == '+')
        s2 = s.substr(1);
    else
        s2 = s;
    if (containsOnly(s2, "0123456789")) {
        convert_int(s2);
    } else if ((containsOnly(s2, "0123456789.") && containsOnlyOneOf(s2, '.')) || s2 == "inf" || s2 == "nan") {
        convert_double(s2);
    } else if ((s2.find('f') == s2.length() - 1&& containsOnly(s2, "0123456789.f") && containsOnlyOneOf(s2, '.') && containsOnlyOneOf(s2, 'f')) \
    || s2 == "inff" || s2 == "nanf") {
        convert_float(s2);
    } else {
        std::cout << "impossible" << std::endl;
    }
}


void ScalarConverter::convert_double(const std::string& scalar) {
    double d = std::strtod(scalar.c_str(), 0);
    double temp;
    double fractionalPart = modf(d, &temp);
    int precision = scalar.find('.') == std::string::npos ? 0 : scalar.length() - scalar.find('.') - 1;
    std::string decimal = fractionalPart == 0 ? ".0" : "";

    if (scalar == "nan" || scalar == "inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << scalar << "f" << std::endl;
        std::cout << "double: " << scalar << std::endl;
        return;
    }
    if (d < 32 || d > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(d) << std::endl;
    }
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "float: " << static_cast<float>(d) << decimal << "f" << std::endl;
    std::cout << "double: " << d << decimal << std::endl;
}

void ScalarConverter::convert_int(std::string scalar) {
    int i = std::atoi(scalar.c_str());

    if (i < 32 || i > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(i) << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convert_float(std::string scalar) {
    int precision = scalar.find('.') == std::string::npos ? 0 : scalar.length() - scalar.find('.') - 2;
    float f = static_cast<float>(std::atof(scalar.c_str()));
    float temp;
    float fractionalPart = modff(f, &temp);
    std::string decimal = fractionalPart == 0 ? ".0" : "";

    if (scalar == "nanf" || scalar == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << scalar << std::endl;
        std::cout << "double: " << scalar.substr(0, scalar.length() - 1) << std::endl;
        return;
    }
    if (f < 32 || f > 126) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(f) << std::endl;
    }
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout <<  std::fixed << std::setprecision(precision) << "float: " << f << decimal << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << decimal << std::endl;
}

void ScalarConverter::convert_char(std::string scalar) {
    char c = scalar[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}