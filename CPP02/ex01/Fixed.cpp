//
// Created by miguel on 18-05-2023.
//

#include "Fixed.hpp"

int Fixed::fractional = 8;

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixed) {
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(fixed << fractional);
}

Fixed::Fixed(const float fixed) {
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(fixed * (1 << fractional)));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

int Fixed::getRawBits() const {
    return fixed;
}

void Fixed::setRawBits(int fixed) {
    this->fixed = fixed;
}

float Fixed::toFloat() const {
    return (float)this->getRawBits() / (1 << fractional);
}

int Fixed::toInt() const {
    return (this->getRawBits() >> fractional);
}

std::ostream &operator<<(std::ostream &os,  Fixed const &fixed) {
    os << fixed.toFloat();
    return os;
}

