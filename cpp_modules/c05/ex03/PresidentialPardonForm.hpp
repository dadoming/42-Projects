#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);

public:
    PresidentialPardonForm(const std::string target);
    ~PresidentialPardonForm();
    void nextPhase(void) const;

    class FileNotOpenException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif