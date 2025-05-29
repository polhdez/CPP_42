#include <iostream>
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main( void ) {
ClapTrap godzilla = ClapTrap("Godzilla");
ScavTrap gundam = ScavTrap("Gundam");
FragTrap mothra = FragTrap("Mothra");
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
mothra.takeDamage(5);
mothra.takeDamage(5);
mothra.takeDamage(5);
mothra.beRepaired(10);
mothra.takeDamage(5);
mothra.highFiveGuys();
return 0;
}
