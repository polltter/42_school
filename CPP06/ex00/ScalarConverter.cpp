#include "ScalarConverter.hpp"

int ScalarConverter::i = 0;
double ScalarConverter::d = 0;
char ScalarConverter::c = 0;
float ScalarConverter::f = 0;

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {(void) copy; return *this;}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {(void) copy;}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::converter(const std::string& str) {
    int type = typeOfNumber(str);
    if (type == INVALID) {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    else if (type == CHAR)
        toChar(str);
    else if (type == INT)
        toInt(str);
    else if (type == FLOAT)
        toFloat(str);
    else if (type == DOUBLE)
        toDouble(str);
    display(str);
}



int ScalarConverter::typeOfNumber(const std::string& s) {
    if (s.length() == 1 && !isdigit(s.at(0)))
        return CHAR;
    else if (checkInt(s))
        return INT;
    else if (checkDouble(s))
        return DOUBLE;
    else if (checkFloat(s))
        return FLOAT;
    return INVALID;
}

bool ScalarConverter::checkInt(const std::string& s) {
    for (unsigned int i = s.at(0) == '-'; i < s.length(); i++) {
        if (!isdigit(s.at(i)))
            return false;
    }
    return true;
}

bool ScalarConverter::checkDouble(const std::string& s) {
    if (s.length() < 3 || !isdigit(s.at(s.length() - 1)) || s.at(s.length() - 2) != '.') {
        return false;
    }
    for (unsigned int i = s.at(0) == '-'; i < (s.length() - 2); i++) {
        if (!isdigit(s.at(i)))
            return false;
    }
    return true;
}

bool ScalarConverter::checkFloat(const std::string& s) {
    if (s.length() < 4 || s.at(s.length() - 1) != 'f' || !checkDouble(s.substr(0, s.length() - 1)))
        return false;
    return true;
}

void ScalarConverter::toChar(const std::string& s) {
    c = s.at(0);
    i = static_cast <int> (c);
    f = static_cast <float> (c);
    d = static_cast <double> (c);
}

void ScalarConverter::toInt(const std::string &s) {
    i = std::atoi(s.c_str());
    c = static_cast <char> (i);
    f = static_cast <float> (i);
    d = static_cast <double> (i);
}

void ScalarConverter::toFloat(const std::string &s) {
    f = std::atof(s.c_str());
    c = static_cast <char> (f);
    i = static_cast <int> (f);
    d = static_cast <double> (f);
}

void ScalarConverter::toDouble(const std::string &s) {
    d = std::atof(s.c_str());
    c = static_cast <char> (d);
    i = static_cast <int> (d);
    f = static_cast <float> (d);
}

void ScalarConverter::display(const std::string& s) {
    if (s == "nan" ||s == "+inf" || s == "-inf" || \
    s == "nanf" ||s == "+inff" || s == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (s == "nan" ||s == "+inf" || s == "-inf") {
            std::cout << "float: " << s << "f" << std::endl;
            std::cout << "double: " << s << std::endl;
        }
        else {
            std::cout << "float: " << s << std::endl;
            std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
        }
        return;
    }
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}


