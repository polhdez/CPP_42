#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <bits/types.h>
#include "Data.hpp"

class Serializer {
private:
  Serializer(void);
  Serializer(const Serializer &serializer);
  const Serializer &operator=(const Serializer &serializer);
  ~Serializer();
public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t *raw);
};
#endif
