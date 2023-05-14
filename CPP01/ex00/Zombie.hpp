#pragma once
#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H

#include "string"
#include "iostream"

class Zombie {

private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie(void);

    void announce(void);
};


#endif //CPP01_ZOMBIE_H
