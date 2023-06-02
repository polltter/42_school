//
// Created by miguel on 02-06-2023.
//

#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
private:
    std::string name;
    AMateria *inventory[4];
public:
    Character();
    Character(std::string name);
    Character &operator=(const Character &src);
    Character(const Character &src);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

};


#endif //CPP04_CHARACTER_HPP
