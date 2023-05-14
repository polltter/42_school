//
// Created by miguel on 29-04-2023.
//

#include "Weapon.hpp"

Weapon::Weapon(void) {
    std::cout << "Weapon created\n";
}

Weapon::Weapon(std::string tipo) {
    this->type = tipo;
}

Weapon::~Weapon() {
    std::cout << "Destroyed weapon,\n";
}

const std::string &Weapon::getType() {
    std::string &ref = this->type;
    return (ref);
}

void Weapon::setType(std::string newType) {
    this->type = newType;
}