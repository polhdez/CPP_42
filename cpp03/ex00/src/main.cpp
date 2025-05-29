#include <iostream>
#include "../includes/ClapTrap.hpp"

int main( void ) {
ClapTrap godzilla = ClapTrap("Godzilla");
godzilla.attack("helicopter");
godzilla.takeDamage(5);
godzilla.takeDamage(5);
godzilla.beRepaired(10);
godzilla.takeDamage(5);
return 0;
}
