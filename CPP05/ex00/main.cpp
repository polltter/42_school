//
// Created by miguel on 29-06-2023.
//

#include "Bureaucrat.hpp"

void	logAttempt( std::string name, int grade)
{
    std::cout << "Trying to construct a bureaucrat named " << name << " with a grade of " << grade << "..." << std::endl;
}

int	main(void)
{
    {
        try
        {
            logAttempt("Marvin", -42);
            Bureaucrat	Marvin("Marvin", -42);
            LOG("\033[1;28mConstruction successful! Printing info:\033[0;m");
            std::cout << Marvin;
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
    }
    {
        LOG("");
        try
        {
            logAttempt("Marvin", 151);
            Bureaucrat	Marvin("Marvin", 151);
            LOG("\033[1;28mConstruction successful! Printing info:\033[0;m");
            std::cout << Marvin;
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
    }
    {
        LOG("");
        try
        {
            logAttempt("Marvin", 1);
            Bureaucrat	Marvin("Marvin", 1);
            LOG("\033[1;28mConstruction successful! Printing info:\033[0;m");
            std::cout << Marvin;
            try
            {
                Marvin.incrementGrade();
                LOG("Managed to increment grade");
                std::cout << Marvin;
            }
            catch(Bureaucrat::GradeTooLowException &e)
            {
                std::cerr << "Incrementation failed because " << e.what() << ".\n";
            }
            catch(Bureaucrat::GradeTooHighException &e)
            {
                std::cerr << "Incrementation failed because " << e.what() << ".\n";
            }
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
    }
    {
        LOG("");
        try
        {
            logAttempt("Marvin", 150);
            Bureaucrat	Marvin("Marvin", 150);
            LOG("\033[1;28mConstruction successful! Printing info:\033[0;m");
            std::cout << Marvin;
            try
            {
                Marvin.decrementGrade();
                LOG("Managed to decrement grade");
                std::cout << Marvin;
            }
            catch(Bureaucrat::GradeTooLowException &e)
            {
                std::cerr << "Decrementation failed because " << e.what() << ".\n";
            }
            catch(Bureaucrat::GradeTooHighException &e)
            {
                std::cerr << "Decrementation failed because " << e.what() << ".\n";
            }
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
    }
    {
        LOG("");
        try
        {
            logAttempt("Marvin", 15);
            Bureaucrat	Marvin("Marvin", 15);
            LOG("\033[1;28mConstruction successful! Printing info:\033[0;m");
            std::cout << Marvin;
            try
            {
                Marvin.incrementGrade();
                LOG("Managed to increment grade");
                std::cout << Marvin;
            }
            catch(Bureaucrat::GradeTooLowException &e)
            {
                std::cerr << "Incrementation failed because " << e.what() << ".\n";
            }
            catch(Bureaucrat::GradeTooHighException &e)
            {
                std::cerr << "Incrementation failed because " << e.what() << ".\n";
            }
            try
            {
                Marvin.decrementGrade();
                LOG("Managed to decrement grade");
                std::cout << Marvin;
            }
            catch(Bureaucrat::GradeTooLowException &e)
            {
                std::cerr << "Decrementation failed because " << e.what() << ".\n";
            }
            catch(Bureaucrat::GradeTooHighException &e)
            {
                std::cerr << "Decrementation failed because " << e.what() << ".\n";
            }

        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Construction failed because " << e.what() << ".\n";
        }
    }
}