#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : 
    _name(name), 
    _isSigned(false), 
    _gradeToSign(gradeToSign), 
    _gradeToExecute(gradeToExecute)
{
    std::cout << "Default name constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooLowException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : 
    _name(other.getName()), 
    _isSigned(other.getSigned()), 
    _gradeToSign(other.getGradeToSign()), 
    _gradeToExecute(other.getGradeToExecute())
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& other)
{
    (void) other;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form has not yet been signed");
}

std::string AForm::getName( void ) const { return(_name); }

bool AForm::getSigned( void ) const { return(_isSigned); }

int AForm::getGradeToSign( void ) const { return(_gradeToSign); }

int AForm::getGradeToExecute( void ) const { return(_gradeToExecute); }

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    else
        _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, AForm &f)
{
    out << "--------------------" << std::endl << \
    "Name: " << f.getName() << std::endl << \
    "Form is signed: " << f.getSigned() << std::endl << \
    "Grade to sign: " << f.getGradeToSign() << std::endl << \
    "Grade to execute: " << f.getGradeToExecute() << std::endl << \
    "--------------------";
    return (out);
}

 // needs to be virtual
void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    else if (getSigned() == 0)
        throw FormNotSignedException();
    // form is signed and grade is high enough
    nextPhase();
}
