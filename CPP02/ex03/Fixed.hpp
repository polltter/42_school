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

    bool operator<(const Fixed &rhs) const;
    bool operator>(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    Fixed &operator=(const Fixed &other);

    Fixed	operator+(Fixed const &src) const;
    Fixed	operator-(Fixed const &src) const;
    Fixed	operator*(Fixed const &src) const;
    Fixed	operator/(Fixed const &src) const;

    Fixed   &operator++();
    Fixed   &operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);


    static Fixed &	min( Fixed & a, Fixed & b);
    static Fixed &	max( Fixed & a, Fixed & b);
    static const Fixed &	min( const Fixed & a, const Fixed & b);
    static const Fixed &	max( const Fixed & a, const Fixed & b);

    int getRawBits() const;
    void setRawBits(int fixed);
    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //CPP02_FIXED_HPP
