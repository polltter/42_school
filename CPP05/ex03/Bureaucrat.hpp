//
// Created by miguel on 29-06-2023.
//
#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP
#include "string"
#include "iostream"
#include <exception>
#include "AForm.hpp"

# define LOG(x) std::cout << x << std::endl;
class Form;
class Bureaucrat {
private:
    std::string const _name;
    int _grade;
    Bureaucrat();
public:
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    std::string const &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm &form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif //CPP05_BUREAUCRAT_HPP