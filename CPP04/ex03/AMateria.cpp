//
// Created by miguel on 01-06-2023.
//

#include "AMateria.hpp"

AMateria::AMateria(): equiped(0) {
    std::cout << "Default AMateria created" << std::endl;
}


AMateria::AMateria(const std::string &type): type(type), equiped(0) {}

AMateria &AMateria::operator=(const AMateria &src) {
    type = src.getType();
	equiped = src.equiped;
    return *this;
}

AMateria::AMateria(const AMateria &src) {
    *this = src;
}

AMateria::~AMateria() {

}

std::string const &AMateria::getType() const {
    return type;
}
