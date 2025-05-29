#include <iostream>
#include <sstream>

class	ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_damage;

	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& clapTrap);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
