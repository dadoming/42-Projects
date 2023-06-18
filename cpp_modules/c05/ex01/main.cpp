#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    std::cout << "-----------------Test 1-----------------" << std::endl;
    try
    {
        Bureaucrat b("bureau", 1);
        Form f("formi", -1, 1);
    
        std::cout << b << std::endl;
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----------------Test 2-----------------" << std::endl;
    try
    {
        Bureaucrat b("Bureau", 10);
        Form f("Formi", 11, 1);

        b.signForm(f);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------Test 3-------------------" << std::endl;
    try
    {
        Bureaucrat b("Bureau", 10);
        Form f("Formi", 9, 1);

        b.signForm(f);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    return (0);
}
