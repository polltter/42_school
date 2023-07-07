//
// Created by miguel on 30-06-2023.
//

#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    virtual ~Intern();

    AForm *makeForm(std::string const &formName, std::string const &target);
    class FormDoesNotExistException: public std::exception {
    public:
        virtual const char *what() const throw();
    };
};


#endif //CPP05_INTERN_HPP
