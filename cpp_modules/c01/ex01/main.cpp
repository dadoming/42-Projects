# include "Zombie.hpp"

# define HORDE_SIZE 2

int main( void )
{
    Zombie *horde = zombieHorde(HORDE_SIZE, "Dude");
    
    if (horde != nullptr)
    {
        std::cout << std::endl;

        for ( int i = 0 ; i < HORDE_SIZE ; i++ )
        {
            horde[i].announce();
        }

        std::cout << std::endl;

        delete[] (horde);
    }
    
    return (0);
}
