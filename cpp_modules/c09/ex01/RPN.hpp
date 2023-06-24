#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <exception>

class RPN
{
private:
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &rhs);
    ~RPN();

public:
    static void calculate(std::string formula);
    class InvalidInputException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

#endif