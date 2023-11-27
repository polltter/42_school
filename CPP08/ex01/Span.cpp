//
// Created by miguel on 16-10-2023.
//

#include "Span.hpp"
#include "limits.h"

Span &Span::operator=(const Span &src) {
    _span = src._span;
    values.assign(src.values.begin(), src.values.end());
	sorted = src.sorted;
    return *this;
}

void Span::addNumber(int n) {
    if (values.size() == _span)
        throw SpanFullException();
    values.push_back(n);
	sorted = false;
}

unsigned Span::shortestSpan() {
    if (values.size() < 2) {
		throw NoSpanException();
	}
	if (!sorted) {
		std::sort(values.begin(), values.end());
		sorted = true;
	}
    if (std::adjacent_find(values.begin(), values.end()) != values.end())
        return 0;
    std::vector<int>::iterator it = values.begin();
    unsigned min = UINT_MAX;
    for (; (it + 1) < values.end(); it++) {
        if (unsigned (*(it + 1) - *it) < min)
            min = *(it + 1) - *it;
        if (min == 1)
            break;
    }
    return min;
}

unsigned Span::longestSpan() {
    if (values.size() < 2) {
		throw NoSpanException();
	}
	if (!sorted) {
		std::sort(values.begin(), values.end());
		sorted = true;
	}
    return *(values.end() - 1) - *values.begin();
}

