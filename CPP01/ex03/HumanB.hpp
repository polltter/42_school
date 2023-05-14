#pragma once
#ifndef CPP01_HUMANB_H
#define CPP01_HUMANB_H

#include "Weapon.hpp"

class HumanB {
private:
    Weapon      *myWeapon;
    std::string myName;

public:
    HumanB(std::string name);
    ~HumanB();
    void    attack(void);
    void    setWeapon(Weapon &newWeapon);
};


#endif //CPP01_HUMANB_H
