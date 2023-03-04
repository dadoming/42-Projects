# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

std::string remove_extra_whitespaces(std::string str);
bool is_empty(std::string str);

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    	std::string grabInputFromUser(std::string prompt);
};

# endif
