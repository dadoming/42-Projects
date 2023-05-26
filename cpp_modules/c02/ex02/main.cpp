#include "Fixed.hpp"

int main(void) 
{
    {
        std::cout << std::endl << "MANDATORY" << std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;

        std::cout << b << std::endl;

        std::cout << Fixed::max( a, b ) << std::endl;
    }
    {
        std::cout << std::endl << "TESTS" << std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << "a = " << a << std::endl;
        std::cout << std::endl;
        std::cout << "++a = " << ++a << std::endl;
        std::cout << "a == 0 = " << a.operator==(0) << std::endl;
        std::cout << std::endl;

        Fixed c = a.operator*(2);
        std::cout << "c = a x 2 and c = " << c << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << std::endl;
        std::cout << "a = " << a++ << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << std::endl;
        std::cout << "b = "<< b << std::endl;
        std::cout << std::endl;
        std::cout << "a < b = " << a.operator<(b) << std::endl;
        std::cout << "a > b = " << a.operator>(b) << std::endl;

        std::cout << "biggest between a and b = " << Fixed::max( a, b ) << std::endl;
        std::cout << "biggest between a and b = " << Fixed::min( a, b ) << std::endl;
    }
    return (0);
}
