//
// Created by miguel on 29-06-2023.
//

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false),
                                                                            _gradeToSign(gradeToSign),
                                                                            _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();

}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

AForm::AForm(const AForm &other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
                                  _gradeToExecute(other._gradeToExecute){
    *this = other;
}

AForm::~AForm() {}

std::string const &AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "AForm " << form.getName() << " is ";
    if (!form.getSigned())
        out << "not ";
    out << "signed. Grade to sign: " << form.getGradeToSign() << ". Grade to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        this->specific_execute();
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form not signed";
}
