//
// Created by miguel on 29-05-2023.
//

#ifndef CPP04_WCAT_HPP
#define CPP04_WCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& src);
    WrongCat &operator=(const WrongCat& src);
    ~WrongCat();

    void makeSound() const;
};


#endif //CPP04_CAT_HPP
