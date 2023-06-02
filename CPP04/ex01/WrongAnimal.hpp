//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_WANIMAL_HPP
#define CPP04_WANIMAL_HPP

#include "iostream"
#include "string"

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);
    WrongAnimal &operator=(const WrongAnimal& src);
    virtual ~WrongAnimal();

    const std::string &getType() const;
    void setType(const std::string &type);
    void makeSound() const;
};


#endif //CPP04_AANIMAL_HPP
