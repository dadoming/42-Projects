#include "Span.hpp"

int main(void)
{
    {
        try
        {
            Span a(5);

            a.addNumber(4);
            a.addNumber(10);
            a.addNumber(0);
            a.addNumber(19);
            a.addNumber(2147483647);
            a.addNumber(-2147483648);
            a.addNumber(2147483648);
            a.addNumber(41);
            a.print();
            std::cout << "Longest span: " << a.longestSpan() << std::endl;
            std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    {
        try
        {
            Span a(15000);

            for (int i = 0; i < 15000; i++)
                a.addNumber(i*4);

            //a.print();
            std::cout << "Longest span: " << a.longestSpan() << std::endl;
            std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    {
        try
        {
            Span a(20);

            a.fillWithSequentialNumbers(20);
            a.print();
            std::cout << "Longest span: " << a.longestSpan() << std::endl;
            std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    {
        try
        {
            Span a(20000);

            a.fillWithRandomNumbers(10);
            a.print();
            std::cout << "Longest span: " << a.longestSpan() << std::endl;
            std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    return (0);
}