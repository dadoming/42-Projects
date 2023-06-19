#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    try
    {
        Intern dude;

        AForm *form = dude.makeForm("robotomy request", "Bender");
        if (form != NULL)
        {
            std::cout << *form << std::endl;

            Bureaucrat b("Bureau", 1);
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    try
    {
        Intern dude;

        AForm *form = dude.makeForm("presidential par", "Bender");
        if (form != NULL)
        {
            std::cout << *form << std::endl;

            Bureaucrat b("Bureau", 1);
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}