//
// Created by miguel on 01-06-2023.
//

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice & src): AMateria() {
    *this = src;
}

Ice &Ice::operator=(const Ice &src) {
    type = src.getType();
    return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
    AMateria *n = new Ice();
    return n;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}
