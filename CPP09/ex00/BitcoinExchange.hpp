//
// Created by miguel on 21-10-2023.
//

#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include "iostream"
#include "fstream"
#include <ctime>
#include <exception>
#include <cstdlib>
#include "map"

#include "utils.hpp"

class BitcoinExchange {
    std::map<time_t, float> exchange;
    std::map<time_t, float>::iterator closest(time_t target);
public:
    BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &src);
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange() {}

    void readDB(std::string io);
    void printDB() {
        std::map<time_t, float>::iterator it = exchange.begin();
        for (; it != exchange.end(); it++) {
            COUT(ctime(&it->first));
            COUT(it->second);
        }
    }

    void evaluateInput(char *);

    class badLineInputException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: Bad input => ";
        }
    };

    class invalidDateException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: Not a valid date";
        }
    };

    class invalidValueException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: Invalid value for quantity";
        }
    };

    class negativeValueException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: not a positive number.";
        }
    };

    class largeValueException: public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Error: too large a number";
        }
    };

	class dateToEarlyException: public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Error: date is not in the database date range.";
		}
	};
};


#endif //CPP09_BITCOINEXCHANGE_HPP
