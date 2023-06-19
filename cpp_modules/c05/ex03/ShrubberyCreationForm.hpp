#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);

public:
    ShrubberyCreationForm(const std::string target);
    ~ShrubberyCreationForm();
    void nextPhase(void) const;

    class FileNotOpenException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif