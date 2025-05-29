#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include <iostream>
# include <sstream>
# include "WrongAnimal.hpp"

class	WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog& cat);
		~WrongDog();
		WrongDog &operator=(const WrongDog& cat);
		void	makeSound() const;
};
#endif
