//
// Created by miguel on 16-10-2023.
#include <cstdlib>
#include "PmergeMe.hpp"
#include "sstream"
#include "ctime"
#include "algorithm"

bool containsOnly(const std::string &str, std::string strToCheck) {
    return str.find_first_not_of(strToCheck) == std::string::npos;
}

template <class ForwardIterator>
bool is_sorted (ForwardIterator first, ForwardIterator last)
{
    if (first==last) return true;
    ForwardIterator next = first;
    while (++next!=last) {
        if (*next<*first)     // or, if (comp(*next,*first)) for version (2)
            return false;
        ++first;
    }
    return true;
}

template <typename T>
void displayArr(T first, T last, const std::string msg) {
    std::string s;
	std::stringstream ss;
	ss << msg;
//	COUT(ss.str());
//	COUT(*first);
	while (first != last) {
        ss << *first;
        ss << ' ';
//        s = ss.str();
        if (ss.str().size() > 25) {
            ss << "[...]";
            break;
        }
        first++;
    }
    COUT(ss.str());
}

int main(int ac, char **av)
{
    if (ac >= 2) {
        std::string input;
        for(int i = 1; i < ac; i++){
            input += av[i];
            input += " ";
        }
        std::stringstream ss(input);
        if (!containsOnly(input, " 0123456789")) {
            COUT("Error in input");
            return (0);
        }
        std::string word;
        std::vector<int> numbersV;
        std::list<int> numbersL;
        while (ss >> word){
            numbersV.push_back(atoi(word.c_str()));
            numbersL.push_back(atoi(word.c_str()));
        }
        displayArr(numbersV.begin(), numbersV.end(), "Before Vector: ");
        displayArr(numbersL.begin(), numbersL.end(), "Before list: ");
        PmergeMe p;
        clock_t t11 = clock();
        numbersV = p.mySortV(numbersV);
        clock_t t12 = clock();
        numbersL = p.mySortL(numbersL);
        clock_t t13 = clock();
        displayArr(numbersV.begin(), numbersV.end(), "After Vector: ");
        displayArr(numbersL.begin(), numbersL.end(), "After List: ");
        std::cout << "Time to process a range of " << numbersV.size() << " elements with std::vector: " << (double )(t12 - t11) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
        std::cout << "Time to process a range of " << numbersV.size() << " elements with std::vector: " << (double)(t13 - t12) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
    }
    else
        COUT("Wrong number of arguments");
}