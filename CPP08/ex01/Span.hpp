//
// Created by miguel on 16-10-2023.
//

#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include "vector"
#include "algorithm"
#include "iostream"

class Span {
unsigned _span;
std::vector<int> values;
bool sorted;
public:
    Span() {sorted = false;};
    Span(unsigned i) { _span = i; sorted = false;}
    Span &operator=(const Span &src);
    Span(const Span &src) {*this = src;}
    ~Span() {};

    void addNumber(int n);
    unsigned shortestSpan();
    unsigned longestSpan();

    class SpanFullException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Span already full, cannot add any more numbers.";
        }
    };
    class NoSpanException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Not enough numbers to determine a span";
        }
    };
};


#endif //CPP08_SPAN_HPP
