#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _gradeToSign;
    int const           _gradeToExecute;

public:
    Form();
    Form(const std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form &operator=(const Form& other);
    ~Form();

    std::string getName( void ) const;
    bool        getSigned( void ) const ;
    int         getGradeToSign( void ) const ;
    int         getGradeToExecute( void ) const ;

    void        beSigned(Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &out, Form &f);

# endif