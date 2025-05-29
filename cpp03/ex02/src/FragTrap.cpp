#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_name = "default";
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name \
	<< " has been created!" << std::endl;
}

FragTrap::FragTrap(const std::string name)
{
	_name = name;
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name \
	<< " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap()
{
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name \
	<< " has been destroyed!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& fragTrap)
{
	_name = fragTrap._name;
	_health = fragTrap._health;
	_energy = fragTrap._energy;
	_damage = fragTrap._damage;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << _name \
	<< " hi fives the other fighters!" << std::endl;
}

