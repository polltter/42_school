//
// Created by miguel on 29-04-2023.
//

#include "string_utils.hpp"

std::string getTextFile(std::ifstream &in) {
    std::string str;
    std::string finalStr;

    while (std::getline(in, str)) {
        finalStr.append(str);
        finalStr.append("\n");
    }
    return finalStr;
}

std::string searchReplace(std::string og, const char *s, const char *r) {
    std::string search(s);
    std::string replace(r);
    size_t      pos;

    if (search.empty())
        return og;
    pos = og.find(search);
    while (pos + 1) {
        og.erase(pos, search.length());
        og.insert(pos, replace);
        pos = og.find(search, pos + replace.length());
    }
    return og;
}