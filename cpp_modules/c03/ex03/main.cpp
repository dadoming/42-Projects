# include "DiamondTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    Diamondtrap d("Chad");

    std::cout << std::endl;
    d.attack("Karen");
    d.attack("Karen");
    
    std::cout << std::endl;
    d.printStats();

    std::cout << std::endl;
    d.guardGate();
    d.highFivesGuys();
    d.whoAmI();


    std::cout << std::endl;
    d.takeDamage(50);
    
    std::cout << std::endl;
    d.printStats();

    std::cout << std::endl;
    d.beRepaired(50);

    std::cout << std::endl;
    d.printStats();

    std::cout << std::endl;
    d.takeDamage(200);
    d.beRepaired(200);

    return (0);
}