# include "Fixed.hpp"

int _fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointValue = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
