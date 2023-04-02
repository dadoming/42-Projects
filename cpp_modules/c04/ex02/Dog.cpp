# include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
    _type = "DOG";
}

Dog::Dog( const Dog& other )
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=( const Dog& other )
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*other._brain);
    return (*this);
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::spitIdea(int i) const
{
    std::cout << _brain->getIdea(i) << std::endl;
}
