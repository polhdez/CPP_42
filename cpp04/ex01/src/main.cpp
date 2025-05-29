#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

int main()
{

	// Checking deep copy
	Dog base;
	{
		Dog tmp;
		base.getBrain().setIdea("BASE IDEA", 0);
		tmp = base;
		std::cout << tmp.getBrain().getIdea(0) << std::endl;
	}

	//More tests
	const Animal* animal = new Animal();
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();
	std::cout << "Object type: " << animal->getType() << " " << std::endl;
	std::cout << "Object type: " << dog->getType() << " " << std::endl;
	std::cout << "Object type: " << cat->getType() << " " << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	dog->getBrain().setIdea("I want a bone", 0);
	std::cout << "Dog idea " << dog->getBrain().getIdea(0) << std::endl;
	dog->getBrain().setIdea("I want a fish", 0);
	std::cout << "Cat idea " << dog->getBrain().getIdea(0) << std::endl;

	delete animal;
	delete dog;
	delete cat;
	return 0;
}
