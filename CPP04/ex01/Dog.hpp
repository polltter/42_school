//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_DOG_HPP
#define CPP04_DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
public:
    Dog();
    Dog(const Dog& src);
    Dog &operator=(const Dog& src);
    ~Dog();
    void makeSound() const;
};


#endif //CPP04_DOG_HPP
