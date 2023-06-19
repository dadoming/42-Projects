#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    std::string const   _name;
    int                 _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat &operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName( void ) const;
    int         getGrade( void ) const ;

    void        incrementGrade( void );
    void        decrementGrade( void );

    void        signForm(AForm &f);

    void       executeForm(AForm const & form);

    class GradeTooHighException : public std::exception
    {
    	public:
    		virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &b);

#endif