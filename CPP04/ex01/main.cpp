//
// Created by miguel on 29-05-2023.
//

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
    {
        const	Animal*	bunch[6];
        for (int i = 0; i < 6; i++)
        {
            if (i % 2)
                bunch[i] = new Dog();
            else
                bunch[i] = new Cat();
        }
        for (int i = 0; i < 6; i++)
        {
            std::cout << i << ": ";
            bunch[i]->makeSound();
        }
        for (int i = 0; i < 6; i++)
            delete bunch[i];
    }
    {
        std::cout << std::endl << "Checking the copy constructors: " << std::endl;
        const 	Dog*	dog = new Dog;
        const	Animal* other = new Dog(*dog);
        dog->makeSound();
        other->makeSound();
        delete dog;
        delete other;
    }
}