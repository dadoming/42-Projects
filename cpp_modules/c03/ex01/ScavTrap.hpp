# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class Scavtrap : public Claptrap
{
public:
    Scavtrap();
    Scavtrap( std::string name );
    Scavtrap( const Scavtrap& other );
    Scavtrap& operator=( const Scavtrap& other );
    ~Scavtrap();

    void guardGate();
    void attack( const std::string& target );

};

#endif
