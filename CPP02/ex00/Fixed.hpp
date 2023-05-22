#pragma once
#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

#include "iostream"

class Fixed {
private:
    int         fixed;
    static int  fractional;

public:
    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);
    int getRawBits() const;
    void setRawBits(int fixed);
};


#endif //CPP02_FIXED_HPP
