//
// Created by miguel on 04-09-2023.
//

#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP


#include <stdint.h>
#include "iostream"

struct Data {
    int content;
};

class Serializer {

public:
    Serializer();
    Serializer(const Serializer&);
    ~Serializer();
    Serializer &operator=(const Serializer&);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


#endif //CPP06_SERIALIZER_HPP
