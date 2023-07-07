//
// Created by miguel on 30-06-2023.
//

#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
private:
    std::string _target;
    PresidentialPardonForm();
public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm();

    std::string const &getTarget() const;
    void specific_execute() const;
};


#endif //CPP05_PRESIDENTIALPARDONFORM_HPP
