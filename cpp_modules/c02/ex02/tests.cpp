#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "TESTS" << std::endl;
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
    std::cout << "a > b = " << Fixed::max( a, b ) << std::endl;
    return 0;
}
