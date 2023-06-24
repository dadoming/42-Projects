#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN \"formula\"" << std::endl;
        return 1;
    }
    RPN::calculate(argv[1]);
    return 0;
}