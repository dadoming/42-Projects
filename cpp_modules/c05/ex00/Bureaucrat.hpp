#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade; // 1 is highest , 150 is lowest
    
    Bureaucrat();

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat &operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName( void ) const;
    int         getGrade( void );

    void        incrementGrade( void );
    void        decrementGrade( void );

     // overriding the what function from the exception class
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

# endif
