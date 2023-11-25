//
// Created by miguel on 21-10-2023.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    exchange = src.exchange;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

void BitcoinExchange::readDB(std::string io) {
    std::string     line;
    std::fstream    fs;
    std::string     data;
    std::string     valor;

    fs.open(io.c_str(), std::fstream::in);
    std::getline(fs, line);
    while (!fs.eof()) {
        if (line == "date,exchange_rate") {
            std::getline(fs, line);
            continue;
        }
        data = line.substr(0, line.find(','));
        trim(data);
        valor = line.substr(line.find(',') + 1, line.length());
        trim(valor);
        try {
            exchange[strToTm(data)] = std::atof(valor.c_str());
        }
        catch (invalidDateException &e) {
            COUT(e.what());
            COUT("continuing...");
            continue;
        }
        std::getline(fs, line);
    }
    fs.close();
}

void BitcoinExchange::evaluateInput(char *io) {
    std::fstream fs;
    fs.open(io, std::fstream::in);
    if (fs.fail()) {
        COUT("Error opening input file.");
        return;
    }
    std::string line;
    std::getline(fs, line);
    if (line != "date | value") {
        COUT("Badly formatted input file.");
        return;
    }
    std::pair<time_t, float> p;
    while (!fs.eof()) {
        if (line == "date | value") {
            std::getline(fs, line);
            continue;
        }
        try {
            p = parseInput(line);
        }
        catch (badLineInputException &e) {
            std::string a("Error: Bad input => " + line);
            COUT(e.what(a));
            std::getline(fs, line);
            continue;
        }
        catch (std::exception &e) {
            COUT(e.what());
            std::getline(fs, line);
            continue;
        }
        std::map<time_t, float>::iterator clo = closest(p.first);
        line.insert(line.find('|'), "=>");
        line.erase(line.find('|'), 1);
        std::cout << line + " = " << p.second * clo->second << std::endl;
        std::getline(fs, line);
    }
    fs.close();
}