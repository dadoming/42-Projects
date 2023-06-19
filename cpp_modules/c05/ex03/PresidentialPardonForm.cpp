#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    *this = other;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

 // needs to be virtual
void PresidentialPardonForm::nextPhase( void ) const
{
    std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
