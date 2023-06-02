//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_AANIMAL_HPP
#define CPP04_AANIMAL_HPP

#include "iostream"
#include "string"
#include "Brain.hpp"

class AAnimal {
protected:
    std::string type;
    Brain       *brain;
public:
    AAnimal();
    AAnimal(const AAnimal& src);
    AAnimal &operator=(const AAnimal& src);
    virtual ~AAnimal();

    const std::string &getType() const;
    void setType(const std::string &type);
    virtual void makeSound() const = 0;
};


#endif //CPP04_AANIMAL_HPP
