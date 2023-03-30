# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main(void)
{
    Scavtrap    scav("Scavy");

    std::cout << std::endl;
    scav.printStats();
    std::cout << std::endl;

    scav.attack("this");
    scav.attack("that");
    scav.attack("other");

    std::cout << std::endl;
    scav.printStats();
    std::cout << std::endl;

    scav.beRepaired(10);

    scav.printStats();
    std::cout << std::endl;

    scav.takeDamage(120);
    scav.attack("LOL");

    scav.guardGate();



    return (0);
}