//
// Created by miguel on 11-04-2023.
//

#include "PhoneBook.h"
int myStoi(std::string str);

std::string ReadPrompt(std::string prompt);


PhoneBook::PhoneBook(void) {
//    std::cout << "Created the phone book" << std::endl;
}

PhoneBook::~PhoneBook(void) {
//    std::cout << "Deleted the phone book" << std::endl;
}

int PhoneBook::find_last(void){
    for (int i = 0; i < 8; i++) {
        if (!this->PhoneList[i].is_empty)
            return (i);
    }
    return (8);
}

void PhoneBook::rotate_contacts() {
    for (int i = 7; i > 0; i--) {
        this->PhoneList[i] = this->PhoneList[i - 1];
        this->PhoneList[i].setIndex(i + 1);
    }
}

void PhoneBook::DisplayAllContacts() {
    for (int i = 0; i < 8; i++){
        this->PhoneList[i].PrintInfo();
    }
}



void PhoneBook::SearchContact() {
//    std::string index;
    int index;

    this->DisplayAllContacts();
    index = myStoi(ReadPrompt("Index of the contact > "));
    while (index < 1 || index > 8)
        index = myStoi(ReadPrompt("Index of the contact > "));
    for (int i = 0; i < 8; i++) {
        if (i + 1 == index)
        {
            this->PhoneList[i].DisplaySearched();
            return;
        }
    }
}

void PhoneBook::AddNew(void) {
    Contact a;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string secret;

    first_name = ReadPrompt("first name? ");
    last_name = ReadPrompt("last name? ");
    nickname = ReadPrompt("nickname? ");
    number = ReadPrompt("number? ");
    secret = ReadPrompt("darkest secret? ");
    a.CreateContact(1, first_name, last_name, nickname, number, secret);
    this->rotate_contacts();
    this->PhoneList[0] = a;
}