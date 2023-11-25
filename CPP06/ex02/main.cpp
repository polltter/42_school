//
// Created by miguel on 25-11-2023.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "exception"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    int i = rand() % 3;
    if (i == 0) {
        std::cout << "A" << std::endl;
        return new A();
    } else if (i == 1) {
        std::cout << "B" << std::endl;
        return new B();
    } else {
        std::cout << "C" << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void) a;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
            (void) b;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
                (void) c;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    return 0;
}