//
// Created by miguel on 02-07-2023.
//

#include "ScalarConverter.hpp"


int main(int ac, char **av) {
    if (ac != 2)
        std::cout << "Invalid number of inputs." << std::endl;
    else {
        ScalarConverter a = ScalarConverter();
        a.converter(av[ac - 1]);
    }
}
