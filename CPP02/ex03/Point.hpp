#pragma once
#ifndef CPP02_POINT_HPP
#define CPP02_POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    ~Point();
    Point();
    Point(float x, float y);
    Point(const Point &src);
    Point &operator=(const Point &other);

    const Fixed &getX() const;
    const Fixed &getY() const;
    Point	operator-(Point const &src) const;
};


#endif //CPP02_POINT_HPP
