# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
    {   // Test 1
        std::cout << std::endl << "--- TEST 1 ---" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        std::cout << std::endl;

        std::cout << "Cat: ";
        i->makeSound(); //will output the cat sound!
        std::cout << "Dog: ";
        j->makeSound();
        std::cout << "Animal: ";
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    {   // Test 2
        std::cout << std::endl << "--- TEST 2 ---" << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << std::endl;

        std::cout << "Wrong Animal: ";
        meta->makeSound();
        std::cout << "Wrong Cat: ";
        i->makeSound(); //will output the wrong cat sound!
        std::cout << std::endl;

        delete i;
        delete meta;
    }
}