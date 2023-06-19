#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    try
    {
        Bureaucrat b1("B1", 1);
        ShrubberyCreationForm s1("this");
        RobotomyRequestForm r1("that");
        PresidentialPardonForm p1("those");

        b1.signForm(s1);
        b1.executeForm(s1);

        b1.signForm(r1);
        b1.executeForm(r1);

        b1.signForm(p1);
        b1.executeForm(p1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b2("B2", 146);
        ShrubberyCreationForm s2("this");
        RobotomyRequestForm r2("that");
        PresidentialPardonForm p2("those");


        b2.signForm(s2);
        b2.executeForm(s2);

        b2.signForm(r2);
        b2.executeForm(r2);

        b2.signForm(p2);
        b2.executeForm(p2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return (0);
}