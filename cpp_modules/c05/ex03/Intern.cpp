# include "Intern.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern &Intern::operator=(const Intern& other)
{
    *this = other;
    return (*this);
}

Intern::~Intern() {}

const char* Intern::InvalidFormNameException::what() const throw()
{
    return ("Invalid form name");
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    AForm *form = NULL;
    try
    {
        if (formName == "robotomy request")
            form = new RobotomyRequestForm(target);
        else if (formName == "presidential pardon")
            form = new PresidentialPardonForm(target);
        else if (formName == "shrubbery creation")
            form = new ShrubberyCreationForm(target);
        else
            throw InvalidFormNameException(); // exits the function with exception
        std::cout << "Intern creates " << formName << std::endl;
        return (form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (form);
}

