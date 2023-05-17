# include "Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "A Zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName( std::string zombie_name)
{
    _name = zombie_name;
}
