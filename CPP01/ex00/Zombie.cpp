//
// Created by miguel on 29-04-2023.
//

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << this->name << " was deleted\n";
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}