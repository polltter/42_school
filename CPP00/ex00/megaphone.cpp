//
// Created by miguel on 11-04-2023.
//

#include "iostream"

std::string toUpperString(std::string str){
    for (long unsigned int i = 0; i < str.length(); ++i) {
        if (isalpha(str[i]))
            str[i] = toupper(str[i]);
    }
    return (str);
}

int main(int ac, char **av) {
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++){
            std::cout << toUpperString(av[i]);
            std::cout << " ";
        }
        std::cout << std::endl;
    }

}