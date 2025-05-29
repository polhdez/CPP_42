#include <iostream>
#include "../includes/ScavTrap.hpp"

int main( void ) {
ClapTrap godzilla = ClapTrap("Godzilla");
ScavTrap gundam = ScavTrap("Gundam");
godzilla.attack("Gundam");
godzilla.takeDamage(5);
godzilla.takeDamage(5);
godzilla.beRepaired(10);
gundam.attack("Godzilla");
gundam.takeDamage(5);
gundam.takeDamage(5);
gundam.takeDamage(5);
gundam.beRepaired(10);
gundam.takeDamage(5);
gundam.guardGate();
return 0;
}
