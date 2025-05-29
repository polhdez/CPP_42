#include "../includes/Zombie.hpp"
#include <cstdio>

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  if (argc < 2)
    return 1;

  int n_zombies;
  if (!sscanf(argv[1], "%d", &n_zombies))
    return 1;
  Zombie *zombie_horde = zombieHorde(n_zombies, argv[2]);
  for (int i=0; i < n_zombies; i++)
  {
    zombie_horde[i].announce();
  }
  delete[] zombie_horde;
  return 0;
}
