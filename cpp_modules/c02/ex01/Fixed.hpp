# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &copy);
    Fixed & operator=(const Fixed &copy);
    ~Fixed();

    float   toFloat( void ) const ;
    int     toInt( void ) const ;

};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

# endif
