//
// Created by miguel on 29-04-2023.
//

#include "Zombie.h++"

Zombie::Zombie(void) {
    std::cout << "Created a zombie\n";
}

Zombie::~Zombie() {
    std::cout << this->name << " was deleted\n";
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string newName) {
    this->name = newName;
}