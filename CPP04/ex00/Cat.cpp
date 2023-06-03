//
// Created by miguel on 29-05-2023.
//

#include "Cat.hpp"

Cat::Cat(): Animal() {
    std::cout << "Cat created" << std::endl;
    setType("Cat");
}

Cat::Cat(const Cat &src): Animal(src) {
    *this = src;
}

Cat &Cat::operator=(const Cat &src) {
    type = src.getType();
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Miau" << std::endl;
}


