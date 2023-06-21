# include "Array.hpp"
# include "iter.hpp"

int main( void )
{
    try
    {
        Array<int> a;
        Array<int> b(3);
        std::cout << "a_size: " << a.size() << std::endl;
        std::cout << "b_size: " << b.size() << std::endl;
        std::cout << "printing b..." << std::endl;
        ::iter(b, 3, print);
        std::cout << "adding 1 to b..." << std::endl;
        ::iter(b, 3, add1);
        std::cout << "printing b again..." << std::endl;
        ::iter(b, 3, print);


        Array<int> c(b);
        c[2] = 42;

        Array<int> d = c;
        std::cout << c[2] << std::endl;
        std::cout << b[2] << std::endl;
        std::cout << d[1] << "..." << d[2] << std::endl;
        d[2] = 21;
        std::cout << c[2] << std::endl;
        std::cout << d[2] << std::endl;

        std::cout << "Getting error: " << std::endl;
        d[4] = 42;
        std::cout << "No error" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Array<std::string> a(5);
        std::cout << std::endl << "a_size: " << a.size() << std::endl;
        std::cout << "printing a..." << std::endl;
        a[0] = "Hello";
        a[1] = 65.7f;
        a[2] = 97;
        a[3] = "Bye";
        ::iter(a, 4, print);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
