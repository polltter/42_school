//
// Created by miguel on 29-06-2023.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this == &other)
        return *this;
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    *this = other;
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
    if (form.getSigned())
        std::cout << this->_name << " cannot sign " << form.getName() << " because it is already signed" << std::endl;
    else {
        try {
            form.beSigned(*this);
            std::cout << this->_name << " signs " << form.getName() << std::endl;
        } catch (std::exception &e) {
            std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
        }
    }
}

void Bureaucrat::executeForm(AForm &form) {
    try {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}
