//
// Created by miguel on 29-05-2023.
//

#include "Dog.hpp"

Dog::Dog(): AAnimal() {
    std::cout << "New dog creted" << std::endl;
    setType("dog");
}

Dog::Dog(const Dog& src): AAnimal(src) {
    *this = src;
}

Dog &Dog::operator=(const Dog &src) {
    type = src.getType();
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "ouf ouf!" << std::endl;
}