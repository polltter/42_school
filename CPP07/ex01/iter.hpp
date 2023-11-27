//
// Created by miguel on 16-10-2023.
//

#ifndef CPP07_ITER_HPP
#define CPP07_ITER_HPP
#include "iostream"

template <typename T>
void iter(T *begin, unsigned int len, void(*func)(T *t)) {
    for (unsigned int i = 0; i < len; i++, begin++) {
        func(begin);
    }
}
#endif //CPP07_ITER_HPP
