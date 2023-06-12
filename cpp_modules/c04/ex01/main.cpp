# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"

# define MAX_ANIMALS 4

int main( void )
{
    const Animal* animals[MAX_ANIMALS];
    
    for (int i = 0; i < MAX_ANIMALS; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
        animals[i]->makeSound();
        animals[i]->spitIdea(4);
    }
    
    for (int i = 0; i < MAX_ANIMALS; i++)
        delete animals[i];
    return (0);
}