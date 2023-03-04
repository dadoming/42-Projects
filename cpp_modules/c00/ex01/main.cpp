#include <iostream>
#include "PhoneBook.hpp"



std::string remove_extra_whitespaces(std::string str);
void displayTitle(int *wrong_input, std::string command);

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		PhoneBook   book;
		std::string command;
		int         oldest_added_index = 0;
		int         wrong_input        = 0;

		while (1)
		{
			displayTitle(&wrong_input, command);
            std::cout << "> ";
            std::getline(std::cin, command);

            if (command.empty())
                continue;

            command = remove_extra_whitespaces(command);
			if (command.compare("ADD") == 0 || command.compare("add") == 0)
			{
                book.addContact(&book.contact[oldest_added_index]);
				oldest_added_index++;
				if (oldest_added_index == 8)
					oldest_added_index = 0;
				wrong_input = 0;
			}

			else if (command.compare("SEARCH") == 0 || command.compare("search") == 0)
			{
				book.searchContact(book.contact);
				wrong_input = 0;
			}

			else if (command.compare("EXIT") == 0 || command.compare("exit") == 0)
				break;
		}
		return (0);
	}
	else 
		std::cout << "This program does not take arguments." << std::endl;
}

void displayTitle(int *wrong_input, std::string command)
{
	if (*wrong_input == 1)
	{
        if (!command.empty())
		    std::cout << "\"" << command << "\"" << ": Invalid command. " << std::endl;
	}
	if (*wrong_input == 0)
	{
		std::cout << "Phonebook commands:" << std::endl;
		std::cout << "ADD:\tAdd a new contact to the phonebook" << std::endl;
		std::cout << "SEARCH:\tSearch for a contact in the phonebook" << std::endl;
		std::cout << "EXIT:\tExit the program" << std::endl;
	}
	*wrong_input = 1;
}
