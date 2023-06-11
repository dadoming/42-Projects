#include "FragTrap.hpp"

Fragtrap::Fragtrap() : Claptrap() { std::cout << "Fragtrap default constructor called" << std::endl; }

Fragtrap::Fragtrap( std::string name ) : Claptrap( name, 100, 30, 100, "FragTrap") { std::cout << "Fragtrap constructor called" << std::endl; }

Fragtrap::Fragtrap( const Fragtrap& other ) : Claptrap( other ) { std::cout << "Fragtrap copy constructor called" << std::endl; *this = other; }

Fragtrap& Fragtrap::operator=( const Fragtrap& other ) { std::cout << "Fragtrap assign operator called" << std::endl; Claptrap::operator=(other); return (*this); }

Fragtrap::~Fragtrap() { std::cout << "Fragtrap destructor called" << std::endl; }

void Fragtrap::attack( const std::string& target )
{
    if (actionPossible())
    {
        std::cout << "\U0001f5e1\uFE0F" << "  " << getTrapType() << " " << getName();
        std::cout << " attacks " << target << " causing " << getAttackDamage();
        std::cout << " points of damage!" << std::endl;
        useEnergyPoint();
    }
    else
        unableToPerform(isDead(), getName(), getTrapType());
}

void Fragtrap::highFivesGuys()
{
    if (actionPossible())
    {
        std::cout << "\U0001f44b" << " " << getTrapType() << " " << getName() << " HIGH FIVES!" << std::endl;
        useEnergyPoint();
    }
    else
        unableToPerform(isDead(), getName(), getTrapType());
}
