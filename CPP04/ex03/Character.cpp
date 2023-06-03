//
// Created by miguel on 02-06-2023.
//

#include "Character.hpp"
#include "lists.hpp"

Character::Character(): name("Default name") {
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(std::string name): name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character &Character::operator=(const Character &src) {
    name = src.getName();
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
        inventory[i] = src.inventory[i]->clone();
    }
    return *this;
}

Character::Character(const Character &src) {
    *this = src;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

const std::string &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!inventory[i])
        {
            inventory[i] = m;
			m->equiped = 1;
            break;
        }
    }
}

void Character::unequip(int idx) {
    inventory[idx]->equiped = 0;
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
    if (inventory[idx]) {
        inventory[idx]->use(target);
    }
}
