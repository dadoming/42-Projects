# include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "CAT";
}

Cat::Cat( const Cat& other )
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=( const Cat& other )
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
} 

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}
