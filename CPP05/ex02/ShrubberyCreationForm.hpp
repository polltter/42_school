//
// Created by miguel on 30-06-2023.
//

#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm{
private:
    std::string _target;
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    virtual ~ShrubberyCreationForm();

    std::string const &getTarget() const;
    void specific_execute() const;
};


#endif //CPP05_SHRUBBERYCREATIONFORM_HPP
