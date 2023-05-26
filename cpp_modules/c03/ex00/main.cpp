# include "ClapTrap.hpp"

int main(void)
{
    {
        std::cout << "Energy Test" << std::endl;
        Claptrap claptrap("Normal Chad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
        claptrap.attack("GigaChad");
    }
    {
        std::cout << "HP Test" << std::endl;
        Claptrap claptrap("Normal Chad");
        claptrap.takeDamage(9);
        claptrap.takeDamage(1);
        claptrap.attack("GigaChad");
        claptrap.takeDamage(1);
    }
    {
        std::cout << "Repair Test" << std::endl;
        Claptrap claptrap("Normal Chad");
        claptrap.takeDamage(9);
        //claptrap.takeDamage(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.beRepaired(1);
        claptrap.attack("GigaChad");
    }
    return (0);
}