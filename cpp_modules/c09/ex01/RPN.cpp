#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
    {
        // Do the copy
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::calculate(std::string formula)
{
    try
    {
        std::stack<int> stack;
        size_t i = 0;
        while (i < formula.length())
        {
            if (isspace(formula[i]))
            {
                i++;
                continue;
            }
            else if (isdigit(formula[i]))
            {
                int num = -1;
                while (isdigit(formula[i]))
                {
                    if (num != -1)
                        throw InvalidInputException();
                    num = formula[i] - '0';
                    i++;
                }
                stack.push(num);
            }
            if (stack.size() < 2 && (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '\0'))
                throw InvalidInputException();
            if(formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/')
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                if (formula[i] == '+')
                    stack.push(b + a);
                else if (formula[i] == '-')
                    stack.push(b - a);
                else if (formula[i] == '*')
                    stack.push(b * a);
                else if (formula[i] == '/')
                    stack.push(b / a);
            }
            i++;
        }
        if (stack.size() != 1)
            throw InvalidInputException();
        std::cout << stack.top() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const char* RPN::InvalidInputException::what() const throw() { return ("Error"); }
