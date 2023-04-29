//
// Created by miguel on 23-04-2023.
//

#include "main.h++"

std::string DeleteSpaces(std::string str)
{
    while (std::isspace(*str.begin()))
        str.erase(0, 1);
    while (std::isspace(*str.end()))
        str.erase(str.size() - 1, 1);
    return str;
}

int myStoi(std::string str) {
    int final = 0;
    int i = 0;

    while (std::isdigit(*(str.begin() + i)) && str[i]) {
        final += final * 10 + str[i] - '0';
        i++;
    }
    return final;
}

std::string ReadPrompt(std::string prompt) {
    std::string str;

    std::cout << prompt;
    std::getline(std::cin, str);
    str = DeleteSpaces(str);
    while (str.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, str);
        str = DeleteSpaces(str);
    }
    return (str);
}


int main(void) {
    std::string input;
    PhoneBook a;

    input = ReadPrompt("Wirte a command >");
    while (input.compare("EXIT")){
        if (!input.compare("ADD"))
            a.AddNew();
        else if (!input.compare("SEARCH"))
            a.SearchContact();
        input = ReadPrompt("Wirte a command >");
    }
}