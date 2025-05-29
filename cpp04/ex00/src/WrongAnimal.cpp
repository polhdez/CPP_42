#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	_type = "default";
	std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	*this = wronganimal;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
	_type = wronganimal._type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimals make no sound!" << std::endl;
}
