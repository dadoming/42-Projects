# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string zombie_name )
{
    if (N <= 0)
    {
        std::cout << "Value: " << N << " is not valid" << std::endl << "Input a value bigger than 0" << std::endl;
        return (nullptr);
    }

    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        horde[i].setZombieName(zombie_name);
    }

    return (horde);
}
