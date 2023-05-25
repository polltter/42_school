//
// Created by miguel on 24-05-2023.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap created" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
    std::cout << "FragTrap default constructor called" << std::endl;
    this->energyPoints = 100;
    this->hitPoints = 100;
    this->attackDamage = 30 ;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap() {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &src) {
    this->name = src.name;
    this->hitPoints = src.hitPoints;
    this->attackDamage = src.attackDamage;
    this->energyPoints = src.energyPoints;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destroyed" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    std::cout << "Fragtrap " << this->name
              << " attacks " << target
              << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
    this->energyPoints--;
}

void FragTrap::highFivesGuys() {
    std::cout << name << ": Can I get an high five!!" << std::endl;
}