#pragma once
#ifndef CPP01_HUMANA_H
#define CPP01_HUMANA_H

#include "Weapon.hpp"

class HumanA {
private:
    Weapon      &myWeapon;
    std::string myName;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void    attack(void);
};


#endif //CPP01_HUMANA_H
