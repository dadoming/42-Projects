# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("UNKNOWN") { std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::WrongAnimal( const WrongAnimal& other ) { std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal& other ) { std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

void WrongAnimal::makeSound() const { std::cout << "Wrong animal!" << std::endl; }

std::string WrongAnimal::getType() const { return (_type); }
