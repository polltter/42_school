//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_ANIMAL_HPP
#define CPP04_ANIMAL_HPP

#include "iostream"
#include "string"

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& src);
    Animal &operator=(const Animal& src);
    virtual ~Animal();

    const std::string &getType() const;
    void setType(const std::string &type);
    virtual void makeSound() const;
};


#endif //CPP04_AANIMAL_HPP
