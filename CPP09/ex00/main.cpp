//
// Created by miguel on 16-10-2023.
#include "utils.hpp"
#include "BitcoinExchange.hpp"

#define COUT(x) std::cout<<x<<std::endl

int main(int ac, char **av)
{
    (void)av;
    if (ac == 2) {
        BitcoinExchange b;
        b.readDB("data.csv");
        b.evaluateInput(av[1]);
    }
    else
        COUT("Wrong number of arguments");
}