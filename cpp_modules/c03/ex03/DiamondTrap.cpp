#include "DiamondTrap.hpp"


Diamondtrap::Diamondtrap() : Claptrap(), Scavtrap(), Fragtrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "_clap_name";
}

Diamondtrap::Diamondtrap(std::string name) : Claptrap(name + "_clap_name", 100, 30, 20), Scavtrap(), Fragtrap() 
{
    std::cout << "DiamondTrap name constructor called" << std::endl;
    _name = name;
}

Diamondtrap::Diamondtrap(const Diamondtrap& other) : Claptrap(other._name + "_clap_name", 100, 30, 20), Scavtrap(), Fragtrap() 
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    _name = other._name;
}

Diamondtrap& Diamondtrap::operator=(const Diamondtrap& other)
{
    std::cout << "DiamondTrap assign operator called" << std::endl;
    _name = other._name;
    Claptrap::operator=(other);
    return (*this);
}

Diamondtrap::~Diamondtrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void Diamondtrap::attack(const std::string& target) { Scavtrap::attack(target); }

void Diamondtrap::whoAmI()
{
    if (actionPossible())
    {
        std::cout << "\U0001f46e" << "  " << "DiamondTrap " << _name << " is " << getName() << std::endl;
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
