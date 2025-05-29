#include <cstddef>
#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  for (int i = 1; argv[i] != NULL; i++)
  {
    for (int j = 0; argv[i][j] != '\0'; j++)
      argv[i][j] = toupper(argv[i][j]);
    std::cout << argv[i];
  }
  std::cout << "\n";
  return 0;
}
