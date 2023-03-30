# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class Diamondtrap : public Scavtrap, public Fragtrap
{

private:
    
    std::string _name;

public:

    Diamondtrap();
    Diamondtrap(std::string name);
    Diamondtrap(const Diamondtrap& other);
    Diamondtrap& operator=(const Diamondtrap& other);
    ~Diamondtrap();

    void whoAmI();
    void attack( const std::string& target );


};

# endif
