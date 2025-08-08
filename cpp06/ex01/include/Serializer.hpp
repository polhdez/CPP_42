#pragma once
#include "Data.hpp"
typedef unsigned long uintptr_t;

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
