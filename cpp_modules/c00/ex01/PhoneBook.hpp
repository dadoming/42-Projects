# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8 

#include "Contact.hpp"

void expandContactByIndex(Contact *contact, int array_size);
void printContactInTable(std::string str);
void displaySearchMenu(Contact *contact, int array_size);
std::string remove_extra_whitespaces(std::string str);
int check_integer(std::string input);

class PhoneBook
{
    public:
        Contact contact[MAX_CONTACTS];

        void addContact(Contact *contact);
        void searchContact(Contact *contact);
};

# endif