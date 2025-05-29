#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name)
{
	_name = name;
	_health = 100;
	_energy = 50;
	_damage = 20;
	_gatekeeper = false;
	std::cout << "ScavTrap " << _name \
	<< " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap) : ClapTrap()
{
	*this = ScavTrap;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() \
	<< " has been destroyed!" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavTrap)
{
	_name = scavTrap._name;
	_health = scavTrap._health;
	_energy = scavTrap._energy;
	_damage = scavTrap._damage;
	_gatekeeper = scavTrap._gatekeeper;
	return (*this);
}

void	ScavTrap::guardGate()
{
	_gatekeeper = true;
	std::cout << "ScavTrap " << _name \
	<< " is in Gate keeper mode!" << std::endl;
}

