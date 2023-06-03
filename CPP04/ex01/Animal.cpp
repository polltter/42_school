//
// Created by miguel on 29-05-2023.
//

#include "Animal.hpp"

Animal::Animal(){
   std::cout << "New animal creted" << std::endl;
   setType("");
   brain = new Brain;
}

Animal::Animal(const Animal& src) {
    brain = new Brain;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) {
    type = src.getType();
    *brain = *src.brain;
    return *this;
}

const std::string &Animal::getType() const {
    return type;
}

void Animal::setType(const std::string &type) {
    Animal::type = type;
}

Animal::~Animal() {
    delete(brain);
    std::cout << "Default animal destroyed" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Makes default sound" << std::endl;
}