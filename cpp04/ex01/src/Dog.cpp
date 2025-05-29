#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
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
        delete _brain;
        _brain = new Brain(*(dog._brain));
    }
    return *this;
}


Dog::~Dog(void)
{
	delete	_brain;
	std::cout << "Dog destroyed!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain&	Dog::getBrain() const
{
	return *_brain;
}
