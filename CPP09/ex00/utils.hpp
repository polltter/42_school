//
// Created by miguel on 21-10-2023.
//

#ifndef CPP09_UTILS_HPP
#define CPP09_UTILS_HPP

#include "iostream"
#include "fstream"
#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include "map"

#define COUT(x) std::cout<<x<<std::endl

void trim(std::string &str);
bool containsOnly(const std::string &str, std::string strToCheck);
time_t strToTm(std::string str);
std::pair<time_t, float> parseInput(std::string &line);

#endif //CPP09_UTILS_HPP
