//
// Created by miguel on 21-05-2023.
//

#include "Point.hpp"

Point::~Point() {}

Point::Point(): x(0), y(0){}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &src) {
    *this = src;
}

Point &Point::operator=(const Point &other) {
    const_cast<Fixed&>(this->x) = other.getX();
    const_cast<Fixed&>(this->y) = other.getY();
    return *this;
}

const Fixed &Point::getX() const {
    return x;
}

const Fixed &Point::getY() const {
    return y;
}

Point Point::operator-(const Point &src) const {
    Fixed a;
    Fixed b;

    a = x - src.getX();
    b = y - src.getY();
    return Point(a.toFloat(), b.toFloat());
}

