#pragma once
#ifndef CPP01_WEAPON_H
#define CPP01_WEAPON_H

#include "string"
#include "iostream"

class Weapon {

private:
    std::string type;

public:
    Weapon();
    Weapon(std::string tipo);
    ~Weapon(void);

    const std::string &getType(void);
    void        setType(std::string);
};


#endif //CPP01_WEAPON_H
