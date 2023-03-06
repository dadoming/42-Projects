# include "Zombie.hpp"

Zombie* newZombie( std::string zombie_name)
{
    Zombie *new_guy = new Zombie(zombie_name);
    
    return (new_guy);
}
