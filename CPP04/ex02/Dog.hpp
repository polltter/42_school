//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_DOG_HPP
#define CPP04_DOG_HPP

#include "AAnimal.hpp"

class Dog: public virtual AAnimal{
public:
    Dog();
    Dog(const Dog& src);
    Dog &operator=(const Dog& src);
    virtual ~Dog();
    virtual void makeSound() const;
};


#endif //CPP04_DOG_HPP
