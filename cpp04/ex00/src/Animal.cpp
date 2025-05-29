#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	_type = "default";
	std::cout << "Animal created!" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
}

Animal&	Animal::operator=(const Animal& animal)
{
	_type = animal._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroyed!" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animals make no sound!" << std::endl;
}
