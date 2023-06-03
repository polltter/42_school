#pragma once
#ifndef CPP03_SCAVTRAP_HPP
#define CPP03_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap:  virtual public ClapTrap{
public:
    ScavTrap();
    ScavTrap(const std::string &n);
    ScavTrap(ScavTrap &src);
    ScavTrap &operator=(ScavTrap const &src);
    virtual ~ScavTrap();
    void attack(const std::string & target);
    void guardGate();
};

#endif //CPP03_SCAVTRAP_HPP
