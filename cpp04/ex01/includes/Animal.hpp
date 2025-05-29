#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <sstream>
# include "Brain.hpp"

class	Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(const Animal& animal);
		virtual ~Animal();
		Animal &operator=(const Animal& animal);

		// Getters & setters
		std::string	getType() const;

		virtual void	makeSound() const;
};

#endif
