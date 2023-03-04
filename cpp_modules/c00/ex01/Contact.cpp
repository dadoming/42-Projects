#include "Contact.hpp"
#include <iostream>

std::string Contact::grabInputFromUser(std::string prompt)
{
    std::string input;

    while (1)
    {
        std::cout << prompt << " ";
        std::getline(std::cin, input);

        if (input.empty() || is_empty(input) == true)
            continue;

        if (input.length()) // testar com espaço e tab
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
