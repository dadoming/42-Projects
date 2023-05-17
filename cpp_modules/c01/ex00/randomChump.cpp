# include "Zombie.hpp"

/*
    Because this zombie is only created in the scope of this function, 
        the destructor will be called when the function ends.
*/
void randomChump( std::string zombie_name)
{
    Zombie( zombie_name ).announce();
}
