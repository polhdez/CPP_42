#ifndef BASE_HPP
#define BASE_HPP

class Base {
  public:
  static Base *generate();
  static void identify(Base *p);
  static void identify(Base &p);
  virtual ~Base() = 0;
};
#endif
