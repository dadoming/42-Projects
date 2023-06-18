#include "Bureaucrat.hpp"

int main( void )
{   
    {
        std::cout << "--- Bureaucrat 1 --- input: 1" << std::endl;
        try
        {
            Bureaucrat b1("Bureaucrat 1", 1);
            std::cout << b1 << std::endl;
            b1.incrementGrade();
            std::cout << "Incremented b1 to " << b1.getGrade() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "--- Bureaucrat 2 --- input: 150" << std::endl;
        try
        {
            Bureaucrat b2("Bureaucrat 2", 150);
            std::cout << b2 << std::endl;
            b2.decrementGrade();
            std::cout << "Decremented b2 to " << b2.getGrade() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "--- Bureaucrat 3 --- input: 151" << std::endl;
        try
        {
            Bureaucrat b3("Bureaucrat 3", 151);
            std::cout << b3 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "--- Bureaucrat 4 --- input: 0" << std::endl;
        try
        {
            Bureaucrat b4("Bureaucrat 4", 0);
            std::cout << b4 << std::endl;
            b4.decrementGrade();
            std::cout << "Decremented b4 to " << b4.getGrade() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "--- Bureaucrat 5 --- input: 42" << std::endl;
        try
        {
            Bureaucrat b5("Bureaucrat 5", 42);
            std::cout << b5 << std::endl;
            b5.incrementGrade();
            std::cout << "Incremented b5 to " << b5.getGrade() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}