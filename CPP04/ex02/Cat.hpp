//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_CAT_HPP
#define CPP04_CAT_HPP

#include "AAnimal.hpp"

class Cat: public AAnimal {
public:
    Cat();
    Cat(const Cat& src);
    Cat &operator=(const Cat& src);
    virtual ~Cat();

    virtual void makeSound() const;
};


#endif //CPP04_CAT_HPP
