# include "Zombie.hpp"

Zombie::Zombie( std::string zombie_name )
{
    _name = zombie_name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
