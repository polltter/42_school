//
// Created by miguel on 02-06-2023.
//

#ifndef CPP04_CURE_HPP
#define CPP04_CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria{
public:
    Cure();
    Cure(const Cure &src);
    Cure &operator=(const Cure &src);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif //CPP04_CURE_HPP
