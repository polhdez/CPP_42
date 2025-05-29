#include <iostream>
#include <sstream>
#include "Animal.hpp"

class	Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& cat);
		~Cat();
		Cat &operator=(const Cat& cat);
		void	makeSound() const;
		Brain&	getBrain() const;
};
