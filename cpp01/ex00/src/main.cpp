#include "../includes/Zombie.hpp"

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  if (argc < 2)
    return 1;
  int n_zombies = argc;
  for (int i = 1; i < n_zombies; i++)
    randomChump(argv[i]);
  return (0);
}
