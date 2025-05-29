#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Dog created!" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	*this = dog;
}

Dog&	Dog::operator=(const Dog& dog)
{
	std::cout << "Dog copy!" << std::endl;
	if (this != &dog) {
		Animal::operator=(dog);
		_type = dog._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
