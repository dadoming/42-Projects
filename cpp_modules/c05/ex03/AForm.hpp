#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const   _name;
    bool                _isSigned;
    int const           _gradeToSign;
    int const           _gradeToExecute;

protected:
    virtual void nextPhase(void) const = 0;

public:
    AForm();
    AForm(const std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm &operator=(const AForm& other);
    virtual ~AForm();

    std::string getName( void ) const;
    bool        getSigned( void ) const ;
    int         getGradeToSign( void ) const ;
    int         getGradeToExecute( void ) const ;

    void        beSigned(Bureaucrat &b);

    void        execute(Bureaucrat const & executor) const;

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

    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm &f);

#endif