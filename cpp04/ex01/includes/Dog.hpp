#include <iostream>
#include <sstream>
#include "Animal.hpp"

class	Dog : public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const Dog& dog);
		~Dog();
		Dog& operator=(const Dog& dog);
		void	makeSound() const;
		Brain&	getBrain() const;
};
