//
// Created by miguel on 21-10-2023.
//

#include "BitcoinExchange.hpp"

void trim(std::string &str) {
    std::string::iterator it = str.begin();
    ulong firstIndex;
    ulong lastIndex;

    while(*it == ' ' && it < str.end())
        it++;
    firstIndex = str.find(*it);
    it = str.end() - 1;
    while (*it == ' ' && it >= str.begin())
        it--;
    lastIndex = str.find_last_of(*it);
    str = str.substr(firstIndex, lastIndex + 1);
}

bool containsOnly(const std::string &str, std::string strToCheck) {
    return str.find_first_not_of(strToCheck) == std::string::npos;
}

time_t strToTm(std::string str) {
    if (str.find('-') == str.rfind('-') || str.find('-') == std::string::npos)
        throw BitcoinExchange::invalidDateException();
    std::string year = str.substr(0, str.find('-'));
    std::string month = str.substr(str.find('-') + 1, 2);
    std::string day = str.substr(str.rfind('-') + 1, 2);
    if (!containsOnly(year, "0123456789") || !containsOnly(month, "0123456789") || !containsOnly(day, "0123456789"))
        throw BitcoinExchange::invalidDateException();
    struct tm t = {};
    t.tm_year = std::atoi(year.c_str()) - 1900;
    t.tm_mon = std::atoi(month.c_str()) - 1;
    t.tm_mday = std::atoi(day.c_str());
    return mktime(&t);

}

std::pair<std::string, std::string> getDateAndValueStrs(std::string &src) {
    std::string date;
    std::string value;

    date = src.substr(0, src.find('|'));
    trim(date);
    value = src.substr(src.find('|') + 1, src.length());
    trim(value);
    return std::pair<std::string, std::string>(date, value);
}

float parseValue(std::string value) {
    if (!containsOnly(value, "-.0123456789"))
        throw BitcoinExchange::invalidValueException();
    float res = atof(value.c_str());
    if (res < 0)
        throw BitcoinExchange::negativeValueException();
    else if (res > 1000)
        throw BitcoinExchange::largeValueException();
    return res;
}

std::pair<time_t, float> parseInput(std::string &line) {
    if (line.find('|') == std::string::npos || line.find('|') != line.rfind('|'))
        throw BitcoinExchange::badLineInputException();
    std::pair<std::string, std::string> dateValueStrs = getDateAndValueStrs(line);
    return std::pair<time_t, float>(strToTm(dateValueStrs.first), parseValue(dateValueStrs.second));
}