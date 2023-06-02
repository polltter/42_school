//
// Created by miguel on 29-05-2023.
//

#include "Animal.hpp"

AAnimal::AAnimal(){
   std::cout << "New animal creted" << std::endl;
   setType("");
}

AAnimal::AAnimal(const AAnimal& src) {
    *this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
    type = src.getType();
    return *this;
}

const std::string &AAnimal::getType() const {
    return type;
}

void AAnimal::setType(const std::string &type) {
    AAnimal::type = type;
}

AAnimal::~AAnimal() {
    std::cout << "Default animal destroyed" << std::endl;
}

void AAnimal::makeSound() const{
    std::cout << "Makes default sound" << std::endl;
}