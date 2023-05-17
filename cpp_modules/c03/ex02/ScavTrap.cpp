# include "ScavTrap.hpp"

Scavtrap::Scavtrap(): Claptrap()
{
    std::cout << "Scavtrap constructor called" << std::endl;
}

Scavtrap::Scavtrap( std::string name ) : Claptrap(name, 100, 50, 20)
{
    std::cout << "Scavtrap constructor called" << std::endl;
}

Scavtrap::Scavtrap( const Scavtrap& other ) : Claptrap(other)
{
    std::cout << "Scavtrap constructor called" << std::endl;
    *this = other;
}

Scavtrap& Scavtrap::operator=( const Scavtrap& other )
{
    std::cout << "Scavtrap assign operator called" << std::endl;
    Claptrap::operator=(other);
    return (*this);
}

Scavtrap::~Scavtrap()
{
    std::cout << "Scavtrap destructor called" << std::endl;
}

void Scavtrap::attack( const std::string& target )
{
    if (actionPossible())
    {
        std::cout << "\U0001f5e1\uFE0F"  << "  " << "Scavtrap " << getName();
        std::cout << " attacks " << target << " causing " << getAttackDamage();
        std::cout << " points of damage!" << std::endl;
        useEnergyPoint();
    }
    else 
    {
        if (isDead())
            std::cout << "\U0001f480" << " " << getName() << " has no HP left!" << std::endl;
        else
            std::cout << "\U0001f62b" << "  " << getName() << " has no energy left!" << std::endl;
    }
}

void Scavtrap::guardGate()
{
    std::cout << "\U0001f6e1\uFE0F" << "  " << getName() << " has entered Gate keeper mode" << std::endl;
    useEnergyPoint();
}