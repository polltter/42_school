//
// Created by miguel on 16-10-2023.
#include "RPN.hpp"


int main(int ac, char **av)
{
    (void)av;
    if (ac == 2) {
        RPN r;
        std::string calc(av[1]);
        r.calculate(calc);
        r.displyResult();
    }
    else
        COUT("Wrong number of arguments");
}