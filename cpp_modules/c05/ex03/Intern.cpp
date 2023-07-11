# include "Intern.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern &Intern::operator=(const Intern& other)
{
    (void) other;
    return (*this);
}

Intern::~Intern() {}

const char* Intern::InvalidFormNameException::what() const throw()
{
    return ("Invalid form name");
}

const std::string formList[3] = { 
    "robotomy request", 
    "presidential pardon", 
    "shrubbery creation"
};

AForm* Intern::makeForm(std::string formName, std::string target)
{
    int i = 0;
    while(i < 3)
    {
        if (formName == formList[i])
            break ;
        i++;
    }

    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return (new RobotomyRequestForm(target));
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return (new PresidentialPardonForm(target));
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return (new ShrubberyCreationForm(target));
        default:
            throw InvalidFormNameException();
    }
}

