#pragma once
#ifndef CPP03_FRAGTRAP_HPP
#define CPP03_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap:  virtual public ClapTrap{
public:
    FragTrap();
    FragTrap(const std::string &n);
    FragTrap(FragTrap const &src);
    FragTrap &operator=(FragTrap const &src);
    virtual ~FragTrap();
    virtual void attack(const std::string & target);
    void highFivesGuys();
};

#endif //CPP03_SCAVTRAP_HPP
