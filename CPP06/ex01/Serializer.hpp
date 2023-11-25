//
// Created by miguel on 23-11-2023.
//

#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data {
    int n;
};

class Serializer {
Serializer() {};
~Serializer() {};
Serializer(Serializer const &src) {*this = src;};
Serializer &operator=(Serializer const &src) {(void)src; return *this;};
public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    };
    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    };
};


#endif //CPP06_SERIALIZER_HPP
