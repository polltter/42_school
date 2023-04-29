//
// Created by miguel on 11-04-2023.
//

#ifndef CPP00_PHONEBOOK_H
#define CPP00_PHONEBOOK_H

#include "Contact.h"

std::string DeleteSpaces(std::string str);

class PhoneBook {
    private:
        Contact PhoneList[8];

        int find_last(void);
        void rotate_contacts(void);
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void AddNew();
        void    DisplayAllContacts(void);
        void SearchContact(void);
};


#endif //CPP00_PHONEBOOK_H
