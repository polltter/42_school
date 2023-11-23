//
// Created by miguel on 02-07-2023.
//
#include "ScalarConverter.hpp"
#include <iostream>
int main(int ac, char **av) {

    if (ac != 2) {
        std::cout << "Usage: ./convert <string>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
