//
// Created by miguel on 22-05-2023.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& n): name(n), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
    this->name = src.name;
    this->hitPoints = src.hitPoints;
    this->attackDamage = src.attackDamage;
    this->energyPoints = src.energyPoints;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destroyed" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << this->name
              << " has taken "
              << amount << " of damage!" << std::endl;
    this->hitPoints -= amount;
    if (hitPoints <= 0)
        std::cout << name << " is weak and died!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    std::cout << "Claptrap " << this->name
    << " attacks " << target
    << ", causing " << this->attackDamage
    << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << this->name
              << " healed "
              << amount << " of hit points!" << std::endl;
    this->hitPoints += amount;
    this->energyPoints--;
}

const std::string &ClapTrap::getName() const {
    return name;
}

void ClapTrap::setName(const std::string &name) {
    ClapTrap::name = name;
}

int ClapTrap::getHitPoints() const {
    return hitPoints;
}

void ClapTrap::setHitPoints(int hitPoints) {
    ClapTrap::hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
    ClapTrap::energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return attackDamage;
}

void ClapTrap::setAttackDamage(int attackDamage) {
    ClapTrap::attackDamage = attackDamage;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &trap) {
    os << "name: " << trap.getName() << ", hitPoints: " << trap.getHitPoints() << ", energyPoints: " << trap.getEnergyPoints()
       << ", attackDamage: " << trap.getAttackDamage();
    return os;
}
