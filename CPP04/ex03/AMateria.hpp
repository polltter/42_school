//
// Created by miguel on 01-06-2023.
//

#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP


#include "iostream"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	AMateria &operator=(AMateria const & src);
	virtual ~AMateria();

	int	equiped;
    std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};



#endif //CPP04_AMATERIA_HPP
