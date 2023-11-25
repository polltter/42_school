//
// Created by miguel on 25-11-2023.
//

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.n = 42;
    uintptr_t raw = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(raw);
    std::cout << ptr->n << std::endl;
    return 0;
}