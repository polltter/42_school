//
// Created by miguel on 29-04-2023.
//

#include "Zombie.h++"

Zombie* newZombie( std::string name ) {
    Zombie *a = new Zombie(name);
    return a;
}