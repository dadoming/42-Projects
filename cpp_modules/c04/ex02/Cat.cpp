# include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
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
    this->_brain = new Brain(*other._brain);
    return (*this);
} 

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow!" << std::endl;
}

void Cat::spitIdea(int i) const
{
    std::cout << _brain->getIdea(i) << std::endl;
}
