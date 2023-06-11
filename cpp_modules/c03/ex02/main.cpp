#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    Claptrap c("Clapy");
    Scavtrap s("Scavy");
    Fragtrap f("Fraggy");

    std::cout << std::endl;
    c.printStats();
    std::cout << std::endl;
    s.printStats();
    std::cout << std::endl;
    f.printStats();
    std::cout << std::endl;

    c.attack("Claptrap");
    s.attack("Scavtrap");
    f.attack("Fragtrap");

    c.takeDamage(10);
    s.takeDamage(10);
    f.takeDamage(10);

    c.beRepaired(10);
    s.beRepaired(10);
    f.beRepaired(10);

    std::cout << std::endl;
    s.printStats();
    std::cout << std::endl;
    f.printStats();

    f.highFivesGuys();
    //for(int i = 0; i < 100; i++)
    //    f.highFivesGuys();
}