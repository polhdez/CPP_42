#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <sstream>

class Brain
{
	private:
		std::string*	_ideas;

	public:
		Brain();
		Brain(const Brain& brain);
		Brain& operator=(const Brain& brain);
		~Brain();
		void setIdea(std::string, int index);
		std::string getIdea(int index) const;
};

#endif
