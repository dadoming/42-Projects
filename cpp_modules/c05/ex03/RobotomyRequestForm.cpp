# include "RobotomyRequestForm.hpp"
# include <cstdlib> 

RobotomyRequestForm::RobotomyRequestForm()
    :
    AForm("Default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    :
    AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    :
    AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    *this = other;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
 // needs to be virtual
void RobotomyRequestForm::nextPhase( void ) const
{
    std::cout << "** Drilling noises **" << std::endl;
    if (rand() % 2 == 0)
        std::cout << getName() << " has been robotomized successfully" << std::endl;
    else
        std::cout << getName() << " robotomy failed" << std::endl;
}
