//
// Created by miguel on 21-10-2023.
//

#ifndef CPP09_RPN_HPP
#define CPP09_RPN_HPP

#include "stack"
#include <cstdlib>
#include "iostream"
#include "string"

#define COUT(x) std::cout<<x<<std::endl

class RPN {
std::stack<float> s;
public:
    RPN() {}
    RPN &operator=(const RPN &src) {s = src.s; return *this;}
    RPN(const RPN &src) {*this = src;}
    ~RPN() {}

    void calculate(std::string calc);
    void displyResult() { if(!s.empty())COUT(s.top());}
};


#endif //CPP09_RPN_HPP
