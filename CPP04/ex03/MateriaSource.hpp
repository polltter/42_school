//
// Created by miguel on 02-06-2023.
//

#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource: public IMateriaSource{
private:
    AMateria *sources[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &src);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &);
};


#endif //CPP04_MATERIASOURCE_HPP
