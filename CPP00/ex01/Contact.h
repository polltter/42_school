//
// Created by miguel on 11-04-2023.
//

#ifndef CPP00_CONTACT_H
#define CPP00_CONTACT_H

#define _GLIBCXX_USE_C99 1

#include "iostream"
#include "iomanip"
#include "string"

class Contact {

private:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:

    int         is_empty;
    Contact(void);
    ~Contact(void);
    void    CreateContact(int, std::string, std::string, std::string, std::string, std::string);
    void    PrintInfo(void);
    void    DisplaySearched(void);
    void    setIndex(int i);
};


#endif //CPP00_CONTACT_H
