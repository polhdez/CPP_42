#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include <sstream>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& cat);
		~WrongCat();
		WrongCat &operator=(const WrongCat& cat);
		void	makeSound() const;
};
#endif
