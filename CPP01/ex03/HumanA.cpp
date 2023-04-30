//
// Created by miguel on 29-04-2023.
//

#include "HumanA.h++"

HumanA::HumanA(std::string name, Weapon &weapon): myWeapon(weapon) {
    this->myName = name;
}

HumanA::~HumanA() {
    std::cout << this->myName << " died!\n";
}

void HumanA::attack() {
    std::cout << this->myName << " attacks with their " << this->myWeapon.getType() << std::endl;
}