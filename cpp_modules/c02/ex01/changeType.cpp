#include "Fixed.hpp"

float Fixed::toFloat( void ) const 
{
    return (( float ) this->_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const 
{
    return (this->_fixedPointValue >> _fractionalBits);
}
