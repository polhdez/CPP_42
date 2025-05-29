#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat)
{
	*this = wrongcat;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongcat)
{
	_type = wrongcat._type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed!" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
