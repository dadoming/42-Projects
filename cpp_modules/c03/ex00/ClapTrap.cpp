#include "ClapTrap.hpp"

Claptrap::Claptrap()
{
    std::cout << "Claptrap constructor called" << std::endl;
}

Claptrap::Claptrap( std::string name )
{
    std::cout << "Claptrap constructor called" << std::endl;
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

Claptrap::Claptrap( const Claptrap& other )
{
    std::cout << "Claptrap constructor called" << std::endl;
    *this = other;
}

Claptrap& Claptrap::operator=( const Claptrap& other )
{
    std::cout << "Claptrap assign operator called" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return *this;
}

Claptrap::~Claptrap()
{
    std::cout << "Claptrap destructor called" << std::endl;
}

void Claptrap::attack( const std::string& target )
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "\U0001f5e1\uFE0F"  << "  " << getName() << " Claptrap";
        std::cout << " attacks " << target << " causing " << getAttackDamage();
        std::cout << " points of damage!" << std::endl;
        this->_energyPoints -= 1;
    }
    else 
    {
        if (this->_hitPoints <= 0)
            std::cout << "\U0001f480" << "  " << getName() << " has no HP left!" << std::endl;
        else
            std::cout << "\U0001f62b" << "  " << getName() << " has no energy left!" << std::endl;
    }
}

void Claptrap::takeDamage( unsigned int amount )
{
    if (this->_hitPoints > 0)
    {
        std::cout << "\U0001f494 ";
        std::cout << getName() << " lost " << amount << " HP!" << std::endl;
        this->_hitPoints -= amount;
    }
    else 
        std::cout << "\U0001f480" << "  " << getName() << " has no HP left!" << std::endl;
}

void Claptrap::beRepaired( unsigned int amount )
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "\U0001f527" << getName() << " has been repaired by ";
        std::cout << amount << " HP!" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
    }
    else 
    {
        if (this->_hitPoints <= 0)
            std::cout << "\U0001f480" << "  " << getName() << " has no HP left!" << std::endl;
        else
            std::cout << "\U0001f62b" << "  " << getName() << " has no energy left!" << std::endl;
    }
}

void Claptrap::printStats()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "AD: " << getAttackDamage() << std::endl;
    std::cout << "HP: " << this->_hitPoints << std::endl;
    std::cout << "Energy: " << this->_energyPoints << std::endl;
}

std::string Claptrap::getName()
{
    return _name;
}

unsigned int Claptrap::getAttackDamage()
{
    return _attackDamage;
}
