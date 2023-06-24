#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Usage: ./PMergeMe <numbers to sort>" << std::endl;
        return 1;
    }

    try
    {
        PMergeMe p;

        p.loadContainers(argv);
        p.printContainers("Before:");
        p.sortContainers();
        p.printContainers("After:");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}