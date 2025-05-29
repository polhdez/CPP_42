#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat created!" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	*this = cat;
}

Cat&	Cat::operator=(const Cat& cat)
{
	std::cout << "Cat copy!" << std::endl;
	if (this != &cat) {
		Animal::operator=(cat);
		_type = cat._type;
		_brain = cat._brain;
	}
	return *this;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destroyed!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain&	Cat::getBrain() const
{
	return *_brain;
}
