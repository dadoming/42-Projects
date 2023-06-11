# include "DiamondTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    Diamondtrap d("Chad");

    std::cout << std::endl;
    d.attack("Blabla");
    d.attack("Blable");
    
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

    std::cout << std::endl;
    
    Scavtrap s("Scavy");
    std::cout << std::endl;
    s.attack("Blabla");
    s.attack("Blable");
    for (int i = 0; i < 50; i++)
    {
        std::cout << "[" << s.getEnergyPoints() << "]" << " ";
        s.guardGate();
    }

    std::cout << std::endl;
    Claptrap c("Clappy");
    std::cout << std::endl;
    c.attack("Blabla");
    c.attack("Blable");

    std::cout << std::endl;
    Fragtrap f("Fraggy");
    std::cout << std::endl;
    f.attack("Blabla");
    f.attack("Blable");
    for (int i = 0; i < 100; i++)
    {
        std::cout << "[" << f.getEnergyPoints() << "]" << " ";
        f.highFivesGuys();
    }
    
    std::cout << std::endl;
    
    

    /* This should force the Wshadow flag to throw a warning, but doesn't (?)
    int x = 42;
    int sum = 0;

    for (int i = 0; i < 10; i++) {
    int x = i;
    std::cout << "x: " << x << '\n'; // prints values of i from 0 to 9
    sum += x;
    }

    std::cout << "sum: " << sum << '\n';
    std::cout << "x:   " << x   << '\n'; // prints out 42
    */
    return (0);
}