#pragma once
#ifndef CPP01_HARL_H
#define CPP01_HARL_H

#include "iostream"
#include "string"

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void (Harl::*f[4])(void);
    std::string levels[4];
public:
    void comlain(std::string level);
    Harl();
    ~Harl();
};


#endif //CPP01_HARL_H
