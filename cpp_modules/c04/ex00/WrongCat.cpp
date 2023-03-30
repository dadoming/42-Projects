# include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    _type = "WRONGCAT";
}

WrongCat::WrongCat( const WrongCat& other )
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=( const WrongCat& other )
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
} 

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "What does the fox say?" << std::endl;
}
