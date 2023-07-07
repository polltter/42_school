//
// Created by miguel on 29-06-2023.
//

#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false),
                                                                         _gradeToSign(gradeToSign),
                                                                         _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();

}

Form &Form::operator=(const Form &other) {
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

Form::Form(const Form &other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
                               _gradeToExecute(other._gradeToExecute){
    *this = other;
}

Form::~Form() {}

std::string const &Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_signed;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is ";
    if (!form.getSigned())
        out << "not ";
    out << "signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}
