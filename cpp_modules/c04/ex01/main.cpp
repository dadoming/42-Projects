# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
    const Animal* animals[10];
    
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    animals[3]->makeSound();
    animals[4]->spitIdea(4);

    for (int i = 0; i < 10; i++)
        delete animals[i];
    
    return (0);
}