#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_gatekeeper;

	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& scavTrap);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& scavTrap);

		void	guardGate(void);
};
