# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class Fragtrap : virtual public Claptrap
{

public:
    Fragtrap();
    Fragtrap( std::string name );
    Fragtrap( const Fragtrap& other );
    Fragtrap& operator=( const Fragtrap& other );
    ~Fragtrap();
    
    void highFivesGuys();
    void attack( const std::string& target );

};


# endif
