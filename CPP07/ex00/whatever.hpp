//
// Created by miguel on 16-10-2023.
//

#ifndef CPP07_WHATEVER_HPP
#define CPP07_WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min (T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T max (T a, T b) {
    return a > b ? a : b;
}

#endif //CPP07_WHATEVER_HPP
