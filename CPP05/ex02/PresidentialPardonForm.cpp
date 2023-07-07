//
// Created by miguel on 30-06-2023.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other)
        this->_target = other._target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string const &PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::specific_execute() const {
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
