#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

Contact::~Contact()
{
}

void Contact::setContact()
{
    std::cout << "Fill in the following fields:" << std::endl;
    std::cout << "(Can't be left in blank.)" << std::endl << std::endl;

    std::string first_name      =  grabInputFromUser("First Name:");
    std::string last_name       =  grabInputFromUser("Last Name:");
    std::string nickname        =  grabInputFromUser("Nickname:");
    std::string phone_number    =  grabInputFromUser("Phone Number:");
    std::string darkest_secret  =  grabInputFromUser("Darkest Secret:");

    this->setContactValues(first_name, \
                          last_name, \
                          nickname, \
                          phone_number, \
                          darkest_secret);

    std::cout << "Contact added!" << std::endl << std::endl;
}

void Contact::setContactValues(std::string first_name, \
                        std::string last_name, \
                        std::string nickname, \
                        std::string phone_number, \
                        std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
    std::cout << getFirstName() << std::endl;
    std::cout << getLastName() << std::endl;
    std::cout << getNickname() << std::endl;
    std::cout << getPhoneNumber() << std::endl;
    std::cout << getDarkestSecret() << std::endl;

}

std::string Contact::getFirstName()
{
    return (this->first_name);
}

std::string Contact::getLastName()
{
    return (this->last_name);
}

std::string Contact::getNickname()
{
    return (this->nickname);
}

std::string Contact::getPhoneNumber()
{
    return (this->phone_number);
}

std::string Contact::getDarkestSecret()
{
    return (this->darkest_secret);
}

std::string grabInputFromUser(std::string prompt)
{
    std::string input;

    while (1)
    {
        std::cout << prompt << " ";
        std::getline(std::cin, input);

        if (input.empty() || is_empty(input) == true)
            continue;

        if (input.length())
            break;
    }
    input = remove_extra_whitespaces(input);
    return (input);
}

bool is_empty(std::string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return (false);
    }
    return (true);
}

std::string remove_extra_whitespaces(std::string str)
{
    int len = str.length();
    while (str[0] == ' ' || str[0] == '\t')
        str.erase(0, 1);
    for (int i = 0; i < len; i++)
    {
        if ((str[i] == ' ' || str[i] == '\t') \
            && ((str[i + 1] == ' ' || str[i + 1] == '\t') || str[i + 1] == '\0'))
        {
            str.erase(i, 1);
            i--;
        }
    }
    return (str);
}
