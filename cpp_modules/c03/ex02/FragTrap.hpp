# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class Fragtrap : public Claptrap
{

public:
    Fragtrap();
    Fragtrap( std::string name );
    Fragtrap( const Fragtrap& other );
    Fragtrap& operator=( Fragtrap const & other );
    ~Fragtrap();
    
    void highFivesGuys();
    void attack( const std::string& target );

};


# endif
