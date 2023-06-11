# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class Claptrap
{

private:

	std::string		        _name;
	int				        _hitPoints;
	int				        _energyPoints;
	unsigned int		    _attackDamage;

	std::string		        _trapType;

public:

	Claptrap();
	Claptrap( std::string name );
	Claptrap( const Claptrap& other );
    Claptrap( std::string name, int hp, int ad, int ep, std::string type );
    Claptrap& operator=( const Claptrap& other );
	~Claptrap();

	void        attack( const std::string& target );
	void        takeDamage( unsigned int amount );
	void        beRepaired( unsigned int amount );
    void        printStats();

    std::string     getName();
    unsigned int    getAttackDamage();
    void            useEnergyPoint();
    bool            actionPossible();
    bool            isDead();
	int				getEnergyPoints();
	
	std::string     getTrapType();
};

void unableToPerform(int dead, std::string name, std::string type);

# endif
