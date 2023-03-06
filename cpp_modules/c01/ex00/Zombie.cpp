# include "Zombie.hpp"

Zombie::Zombie( std::string zombie_name )
{
    name = zombie_name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " has been destroyed" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
