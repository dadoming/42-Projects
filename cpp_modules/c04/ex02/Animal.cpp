# include "Animal.hpp"

Animal::Animal() : _type("UNKNOWN") { std::cout << "Animal default constructor called" << std::endl; }

Animal::Animal( const Animal& other ) { std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=( const Animal& other ) { std::cout << "Animal copy assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

std::string Animal::getType() const { return (_type); }

void Animal::makeSound() const { std::cout << "This is an unknown animal! O.o" << std::endl; }

void Animal::spitIdea(int i) const { (void) i; std::cout << "This animal has no brain!" << std::endl; }
