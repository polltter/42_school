//
// Created by miguel on 30-06-2023.
//

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
        this->_target = other._target;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {

}

std::string const &RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::specific_execute() const {
    std::cout << "*drilling noises* ";
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " robotomization failed" << std::endl;
}
