#include "string"
#include "iostream"

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of string: " << &str <<std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR <<std::endl;
    std::cout << "Address held by stringPTR: " << &stringREF <<std::endl;

    std::cout << "Value of string: " << str <<std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR <<std::endl;
    std::cout << "Value pointed to by stringPTR: " << stringREF <<std::endl;
    return 0;
}
