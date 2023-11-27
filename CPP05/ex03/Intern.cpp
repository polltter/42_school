//ents must have the same ty
// Created by miguel on 30-06-2023.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern::~Intern() {

}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    if (formName == "robotomy request"){
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (formName == "shrubbery creation") {
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (formName == "presidential pardon") {
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
        throw Intern::FormDoesNotExistException();
}

const char *Intern::FormDoesNotExistException::what() const throw() {
    return "Form does not exist";
}
