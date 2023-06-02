//
// Created by miguel on 02-06-2023.
//

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure &Cure::operator=(const Cure &src) {
    type = src.getType();
    return *this;
}

Cure::Cure(const Cure &src): AMateria() {
    *this = src;
}

Cure::~Cure() {

}

AMateria *Cure::clone() const {
    AMateria *n = new Cure();
    return n;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
