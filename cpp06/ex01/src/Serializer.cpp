#include "../include/Serializer.hpp"
#include <cctype>
#include <cfloat>
#include <climits>

Serializer::Serializer(){};

Serializer::Serializer(const Serializer &scalar) {
  (void)scalar;
};

const Serializer &
Serializer::operator=(const Serializer &scalar) {
  (void)scalar;
  return *this;
};

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t *raw) {
  return reinterpret_cast<Data*>(*raw);
}
