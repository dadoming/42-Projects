#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::searchContact()
{
    int array_size = 0;
    while ((array_size <= MAX_CONTACTS - 1) && this->contact[array_size].getFirstName() != "")
        array_size++;

    if (array_size > 0)
    {
        std::cout << "Available contacts:" << std::endl;
        this->displaySearchMenu(array_size);
        this->expandContactByIndex(array_size);
    }
    else
        std::cout << "No contacts available." << std::endl;
}

void PhoneBook::displaySearchMenu(int array_size)
{
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < array_size; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        printContactInTable(this->contact[i].getFirstName());
        printContactInTable(this->contact[i].getLastName());
        printContactInTable(this->contact[i].getNickname());
        std::cout << std::endl;
    }
}

void printContactInTable(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        std::cout << std::right << str << ".|";
    }
    else
    {
        std::cout << std::setw(10) << std::right << str << "|";
    }
}

void PhoneBook::expandContactByIndex(int array_size)
{
    std::cout << "Enter the index of the contact you want to see." << std::endl;
    std::string index;
    int input_value = 0;
    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, index);
        index = remove_extra_whitespaces(index);
        input_value = check_integer(index);
        
        if (index.empty() || input_value > array_size - 1 || input_value < 0)
        {
            std::cout << "Please enter a number from 0 to " << array_size - 1 << "." << std::endl;
            continue;
        }
        break;
    }

    std::cout << std::endl;
    std::cout << "First Name:\t" << this->contact[input_value].getFirstName() << std::endl;
    std::cout << "Last Name:\t" << this->contact[input_value].getLastName() << std::endl;
    std::cout << "Nickname:\t" << this->contact[input_value].getNickname() << std::endl;
    std::cout << "Phone Number:\t" << this->contact[input_value].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret:\t" << this->contact[input_value].getDarkestSecret() << std::endl;
    std::cout << std::endl;
}

int check_integer(std::string input)
{
    if (input.length() == 1)
    {
        if (input[0] >= '0' && input[0] <= '7')
            return (input[0] - 48);
    }
    return (-1);
}