#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include <sstream>
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& cat);
		~Cat();
		Cat &operator=(const Cat& cat);
		void	makeSound() const;
};
#endif
