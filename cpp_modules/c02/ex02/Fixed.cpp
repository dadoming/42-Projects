# include "Fixed.hpp"

Fixed::Fixed()
{
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
    this->_fixedPointValue = (value << _fractionalBits);
}

Fixed::Fixed(const float value)
{
    this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    this->_fixedPointValue = copy._fixedPointValue;
    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const 
{
    return (( float ) this->_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const 
{
    return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixedPointValue++;
    return (temp);
}

Fixed Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixedPointValue--;
    return (temp);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (getRawBits() != fixed.getRawBits());
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}
