//
// Created by miguel on 30-06-2023.
//

#ifndef CPP05_ROBOTOMYREQUESTFORM_HPP
#define CPP05_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
private:
    std::string _target;
    RobotomyRequestForm();
public:
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    virtual ~RobotomyRequestForm();

    std::string const &getTarget() const;
    void specific_execute() const;
};


#endif //CPP05_ROBOTOMYREQUESTFORM_HPP
