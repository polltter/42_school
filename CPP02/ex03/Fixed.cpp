//
// Created by miguel on 18-05-2023.
//

#include "Fixed.hpp"

int Fixed::fractional = 8;

Fixed::Fixed() : fixed(0) {
}

Fixed::Fixed(const int fixed) {
    this->setRawBits(fixed << fractional);
}

Fixed::Fixed(const float fixed) {
    this->setRawBits(roundf(fixed * (1 << fractional)));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &other) {
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

bool Fixed::operator<(const Fixed &rhs) const {
    return fixed < rhs.fixed;
}

bool Fixed::operator>(const Fixed &rhs) const {
    return fixed > rhs.fixed;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return fixed <= rhs.fixed;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return fixed >= rhs.fixed;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return fixed == rhs.fixed;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return rhs.fixed != this->fixed;
}

Fixed Fixed::operator+(const Fixed &src) const {
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const {
    return Fixed(this->toFloat() - src.toFloat());;
}

Fixed Fixed::operator*(const Fixed &src) const {
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const {
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++() {
    fixed++;
    return *this;
}

Fixed &Fixed::operator--() {
    fixed--;
    return *this;
}

Fixed Fixed::operator++(int n) {
    (void)n;
    Fixed temp(this->toFloat());
    fixed++;
    return temp;
}

Fixed Fixed::operator--(int n) {
    (void)n;
    Fixed temp(this->toFloat());
    fixed--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &os,  Fixed const &fixed) {
    os << fixed.toFloat();
    return os;
}

