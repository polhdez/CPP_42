#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <sstream>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_damage;

	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& clapTrap);
		virtual ~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& clapTrap);

		void			setName(const std::string& name);
		void			setHealth(const unsigned int health);
		void			setEnergy(const unsigned int energy);
		void			setDamage(const unsigned int damage);
		std::string		getName(void);
		unsigned int	getHealth(void);
		unsigned int	getEnergy(void);
		unsigned int	getDamage(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
