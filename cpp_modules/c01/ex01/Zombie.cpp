# include "Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "One Zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " has been destroyed" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName( std::string zombie_name)
{
    name = zombie_name;
}
