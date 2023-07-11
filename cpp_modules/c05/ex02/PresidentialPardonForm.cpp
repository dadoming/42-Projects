#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        *this = PresidentialPardonForm(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::nextPhase( void ) const
{
    std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
