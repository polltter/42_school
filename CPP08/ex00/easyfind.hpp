//
// Created by miguel on 16-10-2023.
//

#ifndef CPP08_EASYFIND_HPP
#define CPP08_EASYFIND_HPP


#include <iostream>
#include <algorithm>
#include <iterator>

template <class T>
typename T::iterator easyfind(T &c, int toFind) {
    typename T::iterator it = std::find(c.begin(), c.end(), toFind);
    return it;
}

#endif //CPP08_EASYFIND_HPP
