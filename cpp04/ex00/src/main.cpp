#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongDog.hpp"

int main()
{
const Animal* animal = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
const WrongAnimal* wrongcat = new WrongCat();
const WrongAnimal* wrongdog = new WrongDog();
std::cout << "Object type: " << animal->getType() << " " << std::endl;
std::cout << "Object type: " << dog->getType() << " " << std::endl;
std::cout << "Object type: " << cat->getType() << " " << std::endl;
std::cout << "Object type: " << wrongcat->getType() << " " << std::endl;
std::cout << "Object type: " << wrongdog->getType() << " " << std::endl;
animal->makeSound();
dog->makeSound();
cat->makeSound();
wrongcat->makeSound();
wrongdog->makeSound();
delete animal;
delete dog;
delete cat;
delete wrongcat;
delete wrongdog;
return 0;
}
