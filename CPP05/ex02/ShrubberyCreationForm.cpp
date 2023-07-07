//
// Created by miguel on 30-06-2023.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137),
                                                                           _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
        this->_target = other._target;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const &ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::specific_execute() const {
    std::ofstream file((this->_target + "_shrubbery").c_str());
    file << "      _-_\n"
            "   /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\";
    file.close();
}