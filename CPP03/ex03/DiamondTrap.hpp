#pragma once
#ifndef CPP03_DIAMONDTRAP_HPP
#define CPP03_DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public virtual FragTrap, public virtual ScavTrap{
private:
    std::string name;

public:
    const std::string &getName() const;
    DiamondTrap();
    DiamondTrap(const std::string &);
    DiamondTrap(const DiamondTrap &);
    DiamondTrap &operator=(DiamondTrap const &src);
    ~DiamondTrap();

    virtual void attack(const std::string &);
    void whoAmI();
};


#endif //CPP03_DIAMONDTRAP_HPP
