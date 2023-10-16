//
// Created by miguel on 16-10-2023.
//

#ifndef CPP07_ARRAY_HPP
#define CPP07_ARRAY_HPP
#include "iostream"
template<class T>
class Array {
    long len;
    T *values;
public:
    Array() {
        values = new T[0];
        len = 0;
    }

    Array(unsigned int n) {
        values = new T[n];
        len = n;
    }

    Array &operator=(const Array &src) {
        len = src.len;
        delete [] values;
        values = new T[len];
        for (unsigned i = 0; i < len; i++)
            values[i] = src.values[i];
        return *this;
    }

    Array(const Array &src) {
        values = new T[src.len];
        *this = src;
    }

    T& operator[] (int index) {
        if (index >= len) {
            throw std::out_of_range("Index bigger than array len");
        }
        return values[index];
    }
    int size() {return len;}
};

#endif //CPP07_ARRAY_HPP
