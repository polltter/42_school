//
// Created by miguel on 21-10-2023.
//

#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include "iostream"
#include "vector"
#include "list"

#define COUT(x) std::cout<<x<<std::endl

class PmergeMe {
public:
    PmergeMe() {}
    PmergeMe &operator=(const PmergeMe &src) {(void)src;return *this;}
    PmergeMe(const PmergeMe &src) {*this = src;}
    ~PmergeMe() {}

    std::vector<int> mySortV(std::vector<int> arr);
    std::list<int> mySortL(std::list<int> arr);
};


#endif //CPP09_PMERGEME_HPP
