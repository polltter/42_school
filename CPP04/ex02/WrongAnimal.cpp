//
// Created by miguel on 29-05-2023.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
   std::cout << "New wrong animal creted" << std::endl;
   setType("");
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
    type = src.getType();
    return *this;
}

const std::string &WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::setType(const std::string &type) {
    WrongAnimal::type = type;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Default wrong animal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "Makes wrong default sound" << std::endl;
}