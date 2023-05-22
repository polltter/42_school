#pragma once
#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

#include "iostream"
# include "cmath"

class Fixed {
private:
    int         fixed;
    static int  fractional;

public:
    Fixed();
    Fixed(const int fixed);
    Fixed(const float f);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);
    int getRawBits() const;
    void setRawBits(int fixed);
    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //CPP02_FIXED_HPP
