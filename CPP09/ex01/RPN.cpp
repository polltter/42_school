//
// Created by miguel on 21-10-2023.
//

#include "RPN.hpp"

RPN::RPN() {}
RPN &RPN::operator=(const RPN &src) {(void)src; return *this;}
RPN::RPN(const RPN &src) {*this = src;}
RPN::~RPN() {}

void RPN::displayResult() { if(s.size() == 1)COUT(s.top());}


void RPN::calculate(std::string calc) {
    if (calc.find_first_not_of(" *+-/0123456789") != std::string::npos) {
        COUT("Error.");
        return;
    }
    std::string numbers = "0123456789";
    std::string operations = "/*-+";
    float first;
    float second;
    for (ulong i = 0; i < calc.length(); i++) {
        if (calc[i] == ' ')
            continue;
        else if (calc[i] >= '0' && calc[i] <= '9') {
            s.push(atoi(&calc[i]));
        }
        else {
            if (s.size() < 2) {
                COUT("Error.");
                exit(0);
            }
            first = s.top();
            s.pop();
            second = s.top();
            s.pop();
            switch (calc[i]) {
                case '/':
                    s.push(second / first);
                    break;
                case '*':
                    s.push(second * first);
                    break;
                case '-':
                    s.push(second - first);
                    break;
                case '+':
                    s.push(second + first);
            }
        }
    }
	if (s.size() != 1) {
		COUT("Invalid number of operations or numbers.");
	}
}
