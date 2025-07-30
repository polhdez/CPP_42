#include "../include/Bureaucrat.hpp"
#include <iostream>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  Bureaucrat b1 = Bureaucrat("Pepe", 100);
  Bureaucrat b2 = Bureaucrat("Ramon", -10);
  Bureaucrat b3 = Bureaucrat("Juan", 200);
  Bureaucrat b4 = Bureaucrat("Pedro", 30);

  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  std::cout << b3 << std::endl;
  std::cout << b4 << std::endl;
}
