#include "ClapTrap.hpp"

Claptrap::Claptrap() { std::cout << "Claptrap default constructor called" << std::endl; }

Claptrap::Claptrap( std::string name )
{
    std::cout << "Claptrap constructor called" << std::endl;
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    _trapType = "Claptrap";
}

Claptrap::Claptrap( const Claptrap& other ) { std::cout << "Claptrap copy constructor called" << std::endl; *this = other; }

Claptrap::Claptrap( std::string name, int hp, int ad, int ep, std::string type)
{
    std::cout << "Claptrap childs constructor called" << std::endl;
    _name = name;
    _hitPoints = hp;
    _attackDamage = ad;
    _energyPoints = ep;
    _trapType = type;
}

Claptrap& Claptrap::operator=( const Claptrap& other )
{
    std::cout << "Claptrap assign operator called" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_trapType = other._trapType;
    return *this;
}

Claptrap::~Claptrap() { std::cout << "Claptrap destructor called" << std::endl; }

void Claptrap::attack( const std::string& target )
{
    if (actionPossible())
    {
        std::cout << "\U0001f5e1\uFE0F"  << "  " << getTrapType() << " " << getName();
        std::cout << " attacks " << target << " causing " << getAttackDamage();
        std::cout << " points of damage!" << std::endl;
        useEnergyPoint();
    }
    else 
        unableToPerform(isDead(), getName(), getTrapType());
}

void Claptrap::takeDamage( unsigned int amount )
{
    if (_hitPoints > 0)
    {
        std::cout << "\U0001f494 " << getTrapType() << " " << getName() << " lost " << amount << " HP!" << std::endl;
        _hitPoints -= amount;
    }
    else 
        std::cout << "\U0001f480" << " " << getTrapType() << " " << getName() << " has no HP left!" << std::endl;
}

void Claptrap::beRepaired( unsigned int amount )
{
    if (actionPossible())
    {
        std::cout << "\U0001f527" << " " << getTrapType() << " " << getName() << " has been repaired by ";
        std::cout << amount << " HP!" << std::endl;
        _hitPoints += amount;
        useEnergyPoint();
    }
    else 
        unableToPerform(isDead(), getName(), getTrapType());
}

void Claptrap::printStats()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "AD: " << _attackDamage << std::endl;
    std::cout << "HP: " << _hitPoints << std::endl;
    std::cout << "Energy: " << _energyPoints << std::endl;
    std::cout << "Type: " << _trapType << std::endl;
}

void unableToPerform(int dead, std::string name, std::string type)
{
    if (dead)
        std::cout << "\U0001f480" << " " << type << " " << name << " has no HP left!" << std::endl;
    else
        std::cout << "\U0001f62b" << " " << type << " " << name << " has no energy left!" << std::endl;
}

std::string Claptrap::getTrapType() { return _trapType; }

bool Claptrap::actionPossible() { return (_hitPoints > 0 && _energyPoints > 0); }

void Claptrap::useEnergyPoint() { _energyPoints -= 1; }

std::string Claptrap::getName() { return _name; }

unsigned int Claptrap::getAttackDamage() { return _attackDamage; }

int Claptrap::getEnergyPoints() { return _energyPoints; }

bool Claptrap::isDead() { return (_hitPoints <= 0); }
