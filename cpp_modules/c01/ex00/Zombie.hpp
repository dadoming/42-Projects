# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream> 

class Zombie
{

private:
    std::string _name;


public:
    Zombie( std::string zombie_name );
    ~Zombie();

    void announce( void );

};

Zombie* newZombie( std::string zombie_name);
void randomChump( std::string zombie_name);

# endif
