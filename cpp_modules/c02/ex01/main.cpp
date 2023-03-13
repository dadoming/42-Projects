#include "Fixed.hpp"

/*
    Best tutorial on floating point numbers EVER:
    https://www.youtube.com/watch?v=gc1Nl3mmCuY

    (Double Precision is 64-Bit) Not for right now
    
    << Floating Point Numbers are 32-Bit >>

    <  sign >  ...  < exponent >   ...   < fraction >
    < 1 bit >  ...  < 8   bits >   ...   < 23  bits >
      0 = +,       2^7..2^n..2^0       2^-1..2^-n..2^-23
      1 = -,         

    IEEE 754 floating-point formula:

    [  sign  ] [  1 + mantissa  ] * [  2 ^ (expoent - 127)  ]

*/


std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    
    return (os);
}

int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
