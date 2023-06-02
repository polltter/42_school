//
// Created by miguel on 01-06-2023.
//

#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria{
private:
public:
    Ice();
    Ice &operator=(const Ice &);
    Ice(const Ice &);
    ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif //CPP04_ICE_HPP
