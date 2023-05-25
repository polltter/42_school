//
// Created by miguel on 24-05-2023.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->energyPoints = 50;
    this->hitPoints = 100;
    this->attackDamage = 20 ;
}

ScavTrap::ScavTrap(ScavTrap &src): ClapTrap() {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src) {
    this->name = src.name;
    this->hitPoints = src.hitPoints;
    this->attackDamage = src.attackDamage;
    this->energyPoints = src.energyPoints;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    std::cout << "Scavtrap " << this->name
              << " attacks " << target
              << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}