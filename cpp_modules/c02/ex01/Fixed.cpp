# include "Fixed.hpp"

// https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

// this is the same as value * 2^_fractionalBits
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << _fractionalBits;
}

/*  To convert from floating-point to fixed-point, we follow this algorithm:

    1.Calculate x = floating_input * 2^(fractional_bits)
    2.Round x to the nearest whole number (e.g. round(x))
    3.Store the rounded x in an integer container                           */
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointValue = copy._fixedPointValue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

/*
    Divide the fixed point value by 2^_fractionalBits to get the float value = 256

    When converting a fixed point value to a float, we need to scale the value by 2 ^ -(_fractionalBits)
    to get the correct value. This is because the fixed point value is stored as an integer, and the
    fractional bits are stored as the binary digits after the decimal point. To get the correct value,
    we need to divide the fixed point value by 2 ^ _fractionalBits.

    2 ^ -(_fractionalBits) = 1 / 2 ^ _fractionalBits

*/
float Fixed::toFloat( void ) const 
{
    return ((float) this->_fixedPointValue / (1 << _fractionalBits));
}

// This is the same as value / 2^_fractionalBits
int Fixed::toInt( void ) const 
{
    return (this->_fixedPointValue >> _fractionalBits);
}
