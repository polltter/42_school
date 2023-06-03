//
// Created by miguel on 29-05-2023.
//

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Dog();
    const Animal* j = new Cat();
    const WrongAnimal *w= new WrongCat();


    std::cout << std::endl << "Printing types: " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << w->getType() << " " << std::endl;

    std::cout << std::endl << "Making sounds: " << std::endl;
    std::cout << "Dog: ";
    i->makeSound();
    std::cout << "Cat: ";
    j->makeSound();
    std::cout << "Wrong cat in WrongAnimal body: ";
    w->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete w;
}