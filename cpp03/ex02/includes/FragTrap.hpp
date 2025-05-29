#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();
		FragTrap&	operator=(const FragTrap& fragTrap);
		void	highFiveGuys(void);
};
