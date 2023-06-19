#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <fstream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

public:
    RobotomyRequestForm(const std::string target);
    ~RobotomyRequestForm();
    void nextPhase(void) const;
};

#endif
