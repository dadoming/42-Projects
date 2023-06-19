#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern &operator=(const Intern& other);
        ~Intern();

        AForm *makeForm(std::string formName, std::string target);

    class InvalidFormNameException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif
