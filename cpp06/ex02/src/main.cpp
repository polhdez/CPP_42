#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

Base *generate() {
  switch (rand() % 3) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  }
  return NULL;
}

void identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  if (a) {
    std::cout << "This is an A type pointer!" << std::endl;
    return;
  }
  B *b = dynamic_cast<B *>(p);
  if (b) {
    std::cout << "This is a B type pointer!" << std::endl;
    return;
  }
  C *c = dynamic_cast<C *>(p);
  if (c) {
    std::cout << "This is a C type pointer!" << std::endl;
    return;
  }
  std::cout << "Unknown pointer." << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "This is an A type reference!" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "This is a B type reference!" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "This is a C type reference!" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  std::cout << "Unknown class." << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;
  std::stringstream ss(argv[1]);
  int nVals = 0;
  ss >> nVals;
  if (!nVals)
    return 1;
  // Seed rand so randomness doesnt suck
  srand(time(0));
  for (int i = 0; i < nVals; i++) {
    Base *derived = generate();
    identify(derived);
    identify(*derived);
  }
  return 0;
}
