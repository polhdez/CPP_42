#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <bits/types.h>
#include "Data.hpp"

// This type is missing from cpp98..
typedef unsigned long long uintptr_t;

using std::string;

class Serializer {
private:
  Serializer(void);
  Serializer(const Serializer &serializer);
  const Serializer &operator=(const Serializer &serializer);
  virtual ~Serializer() = 0;

public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t *raw);
};
#endif
