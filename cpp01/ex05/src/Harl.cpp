#include "../includes/Harl.hpp"

Harl::Harl(void)
{
	;
}

Harl::~Harl(void)
{
	;
}

void	Harl::complain(std::string level)
{
	void (Harl::*funs_arr[])(void) = {&Harl::_debug, &Harl::_error, &Harl::_info, &Harl::_warning};
	std::string levels_arr[] = {"DEBUG", "ERROR", "INFO", "WARNING"};

	for (int i = 0; level != levels_arr[i] && i <= 4 ; i++)
		;
}
