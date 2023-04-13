# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8 

#include "Contact.hpp"

void printContactInTable(std::string str);
std::string remove_extra_whitespaces(std::string str);
int check_integer(std::string input);

class PhoneBook
{
public:
    Contact contact[MAX_CONTACTS];

    void searchContact();
    void displaySearchMenu(int array_size);
    void expandContactByIndex(int array_size);

};

# endif