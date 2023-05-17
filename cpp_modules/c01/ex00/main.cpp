#include "Zombie.hpp"

/*
    "When delete is used to deallocate memory for a C++ class object, 
      the object's destructor is called before the object's memory 
      is deallocated (if the object has a destructor)."
*/

int main( void )
{
    // Zombie1
    Zombie *zombie1 = newZombie( "Zito" );
    zombie1->announce();

    std::cout << std::endl;

    // Zombie2
    randomChump( "Tó Mané" );
    
    delete (zombie1);
    return (0);
}
