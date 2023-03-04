#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::addContact(Contact *contact)
{
    std::cout << "Fill in the following fields:" << std::endl;
    std::cout << "(Can't be left in blank.)" << std::endl << std::endl;

    (*contact).first_name      =  (*contact).grabInputFromUser("First Name:");
    (*contact).last_name       =  (*contact).grabInputFromUser("Last Name:");
    (*contact).nickname        =  (*contact).grabInputFromUser("Nickname:");
    (*contact).phone_number    =  (*contact).grabInputFromUser("Phone Number:");
    (*contact).darkest_secret  =  (*contact).grabInputFromUser("Darkest Secret:");

    std::cout << "Contact added!" << std::endl << std::endl;
}

void PhoneBook::searchContact(Contact *contact)
{
    int array_size = 0;
    while (contact[array_size].first_name != "")
    {
        if (array_size > MAX_CONTACTS - 1)
            break;
        array_size++;
    }

    if (array_size > 0)
    {
        std::cout << "Available contacts:" << std::endl;
        displaySearchMenu(contact, array_size);
        
        expandContactByIndex(contact, array_size);
    }
    else
        std::cout << "No contacts available." << std::endl;
}

void displaySearchMenu(Contact *contact, int array_size)
{
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (int i = 0; i < array_size; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        printContactInTable(contact[i].first_name);
        printContactInTable(contact[i].last_name);
        printContactInTable(contact[i].nickname);
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

void expandContactByIndex(Contact *contact, int array_size)
{
    std::cout << "Enter the index of the contact you want to see." << std::endl;
    std::string index;
    int input_value = 0;
    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, index);
        index = remove_extra_whitespaces(index);
        
        try
        {
            input_value = std::stoi(index);
        }
        catch(const std::invalid_argument& e)
        {
            input_value = -1;
        }
        catch(const std::out_of_range& e)
        {
            input_value = -1;
        }

        if (index.empty() || input_value > array_size - 1 || input_value < 0)
        {
            std::cout << "Please enter a number from 0 to " << array_size - 1 << "." << std::endl;
            continue;
        }
        break;
    }

    std::cout << std::endl;
    std::cout << "First Name:\t" << contact[input_value].first_name << std::endl;
    std::cout << "Last Name:\t" << contact[input_value].last_name << std::endl;
    std::cout << "Nickname:\t" << contact[input_value].nickname << std::endl;
    std::cout << "Phone Number:\t" << contact[input_value].phone_number << std::endl;
    std::cout << "Darkest Secret:\t" << contact[input_value].darkest_secret << std::endl;
    std::cout << std::endl;
}
