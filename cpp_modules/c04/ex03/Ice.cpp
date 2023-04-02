# include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice( const Ice& other ) : AMateria(other) {}

Ice &Ice::operator=( const Ice& other )
{
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const { return (new Ice(*this)); }
