//
// Created by miguel on 18-05-2023.
//

#include "Fixed.hpp"

int Fixed::fractional = 8;

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
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
    std::cout << "getRawBits member function called" << std::endl;
    return fixed;
}

void Fixed::setRawBits(int fixed) {
    this->fixed = fixed;
}
