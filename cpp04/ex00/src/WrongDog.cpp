#include "../includes/WrongDog.hpp"

WrongDog::WrongDog(void)
{
	_type = "WrongDog";
	std::cout << "WrongDog created!" << std::endl;
}

WrongDog::WrongDog(const WrongDog& WrongDog) : WrongAnimal(WrongDog)
{
	*this = WrongDog;
}

WrongDog&	WrongDog::operator=(const WrongDog& WrongDog)
{
	_type = WrongDog._type;
	return *this;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destroyed!" << std::endl;
}

void	WrongDog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
