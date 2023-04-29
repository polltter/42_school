//
// Created by miguel on 11-04-2023.
//

#include "Contact.h"
#include "string"

Contact::Contact(void) {
//    std::cout << "Created a new contact" << std::endl;
    this->is_empty = 0;
    this->index = 0;
}

Contact::~Contact(void){
//    std::cout << "Destroyed contact" << std::endl;
}

void Contact::setIndex(int i) {
    this->index = i;
}

void Contact::CreateContact (int id, std::string first, std::string last, std::string nick, std::string number, std::string secret) {
    this->index = id;
    this->first_name = first;
    this->last_name = last;
    this->nickname = nick;
    this->phone_number = number;
    this->darkest_secret = secret;
    this->is_empty = 1;
}

void Contact::DisplaySearched() {
    std::cout << this->first_name << std::endl;
    std::cout << this->last_name << std::endl;
    std::cout << this->nickname << std::endl;
    std::cout << this->phone_number << std::endl;
    std::cout << this->darkest_secret << std::endl;
}

void Contact::PrintInfo(void) {
    std::cout << std::setw(10) << this->index << "|";
    if (this->first_name.size() > 9)
        std::cout << this->first_name.substr(0,9) << "."<< "|";
    else
        std::cout << std::setw(10) << this->first_name << "|";
    if (this->last_name.size() > 9)
        std::cout << this->last_name.substr(0,9) << "."<< "|";
    else
        std::cout << std::setw(10) << this->last_name << "|";
    if (this->nickname.size() > 9)
        std::cout << this->nickname.substr(0,9) << "."<< std::endl;
    else
        std::cout << std::setw(10) << this->nickname << std::endl;
}
