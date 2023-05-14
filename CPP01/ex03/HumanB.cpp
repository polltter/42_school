//
// Created by miguel on 29-04-2023.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->myName = name;
    this->myWeapon = 0;
}

HumanB::~HumanB() {
    std::cout << this->myName << " died!\n";
}

void HumanB::attack() {
    if (!this->myWeapon)
        std::cout << this->myName << " attacks with their bare hands\n";
    else
        std::cout << this->myName << " attacks with their " << this->myWeapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon) {
    this->myWeapon = &newWeapon;
}