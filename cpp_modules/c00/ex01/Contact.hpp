# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

std::string remove_extra_whitespaces(std::string str);
bool is_empty(std::string str);

class Contact
{

private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

public:
        Contact();
        ~Contact();
        
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();

        void setContact();
        void setContactValues(std::string first_name, \
                        std::string last_name, \
                        std::string nickname, \
                        std::string phone_number, \
                        std::string darkest_secret);
};

std::string grabInputFromUser(std::string prompt);

# endif
