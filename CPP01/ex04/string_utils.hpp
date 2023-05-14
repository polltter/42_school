//
// Created by miguel on 29-04-2023.
//

#ifndef CPP01_STRING_UTILS_H
#define CPP01_STRING_UTILS_H

#include "string"
#include "iostream"
#include "fstream"

std::string getTextFile(std::ifstream &in);
std::string searchReplace(std::string og, const char *s, const char *r);


#endif //CPP01_STRING_UTILS_H
