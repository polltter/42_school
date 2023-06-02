//
// Created by miguel on 30-05-2023.
//

#include "Brain.hpp"

const std::string *Brain::getIdeas() const {
    return ideas;
}

Brain::Brain() {
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &src) {
    *this = src;
}

Brain &Brain::operator=(const Brain &src) {
    for (int i = 0; i < 100; i++){
        ideas[i] = src.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}
