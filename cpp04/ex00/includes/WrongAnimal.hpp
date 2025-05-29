#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <sstream>

class	WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wronganimal);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal& wronganimal);

		// Getters & setters
		std::string	getType() const;

		void	makeSound() const;
};

#endif
