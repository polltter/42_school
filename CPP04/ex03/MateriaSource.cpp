//
// Created by miguel on 02-06-2023.
//

#include "MateriaSource.hpp"
#include "lists.hpp"

MateriaSource::MateriaSource(): IMateriaSource(){
    for (int i = 0; i < 4; i++) {
        sources[i] = 0;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    for (int i = 0; i < 4; ++i) {
        delete sources[i];
        sources[i] = src.sources[i]->clone();
    }
    return *this;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    *this = src;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete (sources[i]);
    }
}

void MateriaSource::learnMateria(AMateria *src) {
    for (int i = 0; i < 4; i++) {
        if (!sources[i]) {
            sources[i] = src->clone();
            break;
        }
    }
    delete (src);
}

AMateria *MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++) {
        if (sources[i]->getType() == type)
            return add_list(sources[i]->clone())->cont;
    }
    return 0;
}
