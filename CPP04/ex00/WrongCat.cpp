//
// Created by miguel on 29-05-2023.
//

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
    std::cout << "WrongCat created" << std::endl;
    setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src) {
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
    type = src.getType();
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Wrong miau" << std::endl;
}


