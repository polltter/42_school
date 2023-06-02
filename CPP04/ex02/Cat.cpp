//
// Created by miguel on 29-05-2023.
//

#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat created" << std::endl;
    setType("Cat");
}

Cat::Cat(const Cat &src): AAnimal(src){
    *this = src;
}

Cat &Cat::operator=(const Cat &src) {
    type = src.getType();
    brain = src.brain;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Miau" << std::endl;
}


