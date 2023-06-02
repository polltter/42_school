//
// Created by miguel on 30-05-2023.
//

#ifndef CPP04_BRAIN_HPP
#define CPP04_BRAIN_HPP

#include "string"
#include "iostream"

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& src);
    Brain &operator=(const Brain& src);
    ~Brain();

    const std::string *getIdeas() const;
};


#endif //CPP04_BRAIN_HPP
