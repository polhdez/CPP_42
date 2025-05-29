#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
	_name = name;
	_health = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "ClapTrap " << _name \
	<< " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name \
	<< " has been destroyed!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& clapTrap)
{
	_name = clapTrap._name;
	_health = clapTrap._health;
	_energy = clapTrap._energy;
	_damage = clapTrap._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy < 1)
		return ;
	_energy--;
	std::cout << "ClapTrap " << _name \
	<< " attacks " << target << ", causing " << _damage \
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_health < amount)
		_health = 0;
	else
		_health -= amount;
	std::cout << "ClapTrap " << _name
		<< " took " << amount << " points of damage!" << std::endl;
	if (_health == 0)
		std::cout << "ClapTrap " << _name << " died!" << std::endl;

}
void	ClapTrap::beRepaired(unsigned int amount)
{
	_health += amount;
	std::cout << "ClapTrap " << _name
	<< "has been repaired by " << amount
	 << " health points!" << std::endl;
}
