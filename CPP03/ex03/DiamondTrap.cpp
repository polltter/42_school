//
// Created by miguel on 24-05-2023.
//

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap() {
    std::cout << "DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &n): ClapTrap(n + "_clap_name") ,FragTrap(n), ScavTrap(n), name(n){
    std::cout << "Diamond default constructor called" << std::endl;
    FragTrap::hitPoints = 100;
    FragTrap::attackDamage = 30;
    energyPoints = ScavTrap::energyPoints;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src):ClapTrap(), FragTrap(), ScavTrap() {
    std::cout << "Diamond copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src) {
    this->name = src.name;
    this->hitPoints = src.hitPoints;
    this->attackDamage = src.attackDamage;
    this->energyPoints = src.energyPoints;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamandTrap destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string &n) {
    ScavTrap::attack(n);
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is: " << name << " and my ClapTrap name is: " << ClapTrap::name << std::endl;
}

const std::string &DiamondTrap::getName() const {
    return name;
}
