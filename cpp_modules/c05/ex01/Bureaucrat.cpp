# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
    std::cout << "Default name constructor called" << std::endl;
    this->_name = name;
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_name = other._name;
    this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    *this = other;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName( void ) { return(_name); }

int Bureaucrat::getGrade( void ) { return(_grade); }

std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << "--------------------" << std::endl << \
    "Name: " << b.getName() << std::endl << \
    "Bureaucrat grade: " << b.getGrade() << std::endl << \
    "--------------------";
    return (out);
}

void Bureaucrat::incrementGrade( void )
{
    if (getGrade() - 1 < 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade( void )
{
    if (getGrade() + 1 > 150)
        throw GradeTooLowException();
    else
        _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signs " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
    }
}