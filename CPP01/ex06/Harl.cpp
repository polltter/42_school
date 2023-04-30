//
// Created by miguel on 29-04-2023.
//

#include "Harl.h++"

Harl::Harl() {
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    f[0] = &Harl::debug;
    f[1] = &Harl::info;
    f[2] = &Harl::warning;
    f[3] = &Harl::error;
}

Harl::~Harl() {
//    std::cout << "Harl was so annoyed that he left the store!\n";
}

void Harl::debug() {
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
    this->info();
}

void Harl::info() {
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
    this->warning();
}

void Harl::warning() {
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
    this->error();
}

void Harl::error() {
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::comlain(std::string level) {
    int l;

    l = -1;
    while (++l < 4)
        if (this->levels[l] == level)
            break ;
    switch (l) {
        case (0):
            this->debug();
            break ;
        case (1):
            this->info();
            break ;
        case (2):
            this->warning();
            break ;
        case (3):
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}