#pragma once
#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP

#include "string"
#include "iostream"

class ClapTrap {
protected:
    std::string name;
    int         hitPoints;
    int         energyPoints;
    int         attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string&);
    ClapTrap(ClapTrap &src);
    ClapTrap &operator=(ClapTrap const &src);
    virtual ~ClapTrap();

    void attack(const std::string & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int getAttackDamage() const;
    void setAttackDamage(int attackDamage);
    int getEnergyPoints() const;
    void setEnergyPoints(int energyPoints);
    int getHitPoints() const;
    void setHitPoints(int hitPoints);
    const std::string &getName() const;

    void setName(const std::string &name);

};

std::ostream &operator<<(std::ostream &os, const ClapTrap &trap);

#endif //CPP03_CLAPTRAP_HPP
