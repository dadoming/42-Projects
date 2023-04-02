#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ClearMateria.hpp"

int main( void )
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }
    std::cout << std::endl << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        
        ICharacter *player = new Character("player");
        std::cout << "Created player" << std::endl;

        player->equip(new Ice());
        std::cout << "Player created and equiped Ice" << std::endl;
        player->equip(new Cure());
        std::cout << "Player created and equiped Cure" << std::endl;
        player->equip(src->createMateria("ice"));
        std::cout << "Player created and equiped Ice" << std::endl;
        player->equip(src->createMateria("cure"));
        std::cout << "Player created and equiped Cure" << std::endl;
        
        // Should output error
        //AMateria *tmp = AMateria("lightning");

        player->unequip(0);
        std::cout << "Player unequiped Ice and left it on the floor" << std::endl;
        player->unequip(1);
        std::cout << "Player unequiped Cure and left it on the floor" << std::endl;

        ICharacter *enemy = new Character("enemy");
        std::cout << "Player tries to use Ice but can't" << std::endl;
        player->use(0, *enemy);
        std::cout << "Player tries to use Cure but can't" << std::endl;
        player->use(1, *enemy);
        std::cout << "Player tries to use Ice" << std::endl;
        player->use(2, *enemy);
        std::cout << "Player tries to use Cure" << std::endl;
        player->use(3, *enemy);

        
        clearDroppedMateria();
        delete enemy;
        delete player;
        delete src;
    }   
}
