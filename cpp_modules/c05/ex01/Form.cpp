# include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : 
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

Form::Form(const Form& other) : 
    _name(other.getName()), 
    _isSigned(other.getSigned()), 
    _gradeToSign(other.getGradeToSign()), 
    _gradeToExecute(other.getGradeToExecute())
{
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    *this = other;
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}


/*
    In C++, you can declare the exceptions that a function may throw as part 
        of its function signature. The "throw()" syntax specifies that the 
        function does not throw any exceptions. This is known as an empty 
        exception specification.

    However, it's worth noting that starting from C++11, empty exception 
        specifications (throw()) are deprecated and considered redundant. 
        In modern C++, it is generally recommended to use the "noexcept" 
        keyword instead. The "noexcept" keyword explicitly states that a 
        function does not throw any exceptions. Here's an example of the 
        equivalent code using "noexcept":
*/
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form &f)
{
    out << "--------------------" << std::endl << \
    "Name: " << f.getName() << std::endl << \
    "Sign: " << f.getSigned() << std::endl << \
    "Grade to sign: " << f.getGradeToSign() << std::endl << \
    "Grade to execute: " << f.getGradeToExecute() << std::endl << \
    "--------------------";
    return (out);
}

void    Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() >= getGradeToSign())
        throw GradeTooLowException();
    else
        _isSigned = true;
}

std::string Form::getName( void ) const { return(_name); }

bool Form::getSigned( void ) const { return(_isSigned); }

int Form::getGradeToSign( void ) const { return(_gradeToSign); }

int Form::getGradeToExecute( void ) const { return(_gradeToExecute); }