//
// Created by miguel on 29-06-2023.
//

#ifndef CPP05_AFORM_HPP
#define CPP05_AFORM_HPP

#include "string"
#include "iostream"
#include "../ex01/Bureaucrat.hpp"
class Bureaucrat;

class AForm {
private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;
    AForm();
public:
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();

    std::string const &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const &bureaucrat);
    void execute(Bureaucrat const &executor) const;
    virtual void specific_execute() const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif //CPP05_FORM_HPP
