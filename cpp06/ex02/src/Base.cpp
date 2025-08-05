#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *Base::generate() {
  srand(time(0));
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

void Base::identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  if (a != NULL) {
    std::cout << "this is an A type pointer!" << std::endl;
    return;
  }
  B *b = dynamic_cast<B *>(p);
  if (b != NULL) {
    std::cout << "this is a B type pointer!" << std::endl;
    return;
  }
  C *c = dynamic_cast<C *>(p);
  if (c != NULL) {
    std::cout << "this is a C type pointer!" << std::endl;
    return;
  }
  std::cout << "Unknown pointer." << std::endl;
}

void Base::identify(Base &p) {
    A *a = dynamic_cast<A *>(&p);
    if (a != NULL) {
      std::cout << "this is an A type class!" << std::endl;
      return;
    }
    B *b = dynamic_cast<B *>(&p);
    if (b != NULL) {
      std::cout << "this is a B type class!" << std::endl;
      return;
    }
    C *c = dynamic_cast<C *>(&p);
    if (c != NULL) {
      std::cout << "this is a C type class!" << std::endl;
      return;
    }
    std::cout << "Unknown class." << std::endl;
}
