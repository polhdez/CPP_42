# include "../includes/Brain.hpp"

Brain::Brain()
{
	_ideas = new(std::string[100]);
	std::cout << "Brain created!" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	_ideas = new(std::string[100]);
	std::cout << "Copying ideas via copy constructor" << std::endl;
	for (int i=0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	*this = brain;
}

Brain&	Brain::operator=(const Brain& brain)
{
	std::cout << "Deep copying brain's ideas!" << std::endl;
	for (int i=0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return *this;
}

Brain::~Brain()
{
	delete[] _ideas;
	std::cout << "Brain destroyed!" << std::endl;
}

void Brain::setIdea(std::string idea, int index)
{
	if (index >= 100)
		std::cout << "Index out of bounds!" << std::endl;
	_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 100)
		std::cout << "Index out of bounds!" << std::endl;
	return _ideas[index];
}

