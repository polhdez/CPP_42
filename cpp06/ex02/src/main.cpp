#include "../include/Base.hpp"

int main(int argc, char **argv) {
  (void)argv;
  (void)argc;
  for (int i = 0; i < 10; i++)
  {
      Base *derived = Base::generate();
      Base::identify(derived);
      Base::identify(*derived);
  }
  // Base *derived = Base::generate();
  // Base::identify(derived);
  // Base::identify(*derived);
  return 0;
}
