#pragma once
#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include "string"
#include "iostream"

class Zombie {

private:
    std::string name;

public:
    Zombie(void);
    ~Zombie(void);

    void announce(void);
    void setName(std::string newName);
};


#endif //CPP01_ZOMBIE_H
