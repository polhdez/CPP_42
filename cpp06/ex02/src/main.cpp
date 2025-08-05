#include "../include/Base.hpp"
#include <iostream>

int main(int argc, char **argv) {
  (void)argv;
  (void)argc;
  Base *derived = Base::generate();
  Base::identify(derived);
  Base::identify(*derived);
}
