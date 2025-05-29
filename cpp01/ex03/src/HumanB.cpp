#include "../includes/HumanB.hpp"

HumanB::~HumanB()
{
	;
}

HumanB::HumanB(std::string name)
{
	_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << _name + " attacks with their " << _weapon->getType() + "\n";
}
