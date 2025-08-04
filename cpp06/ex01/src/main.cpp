#include "../include/Data.hpp"
#include "../include/Serializer.hpp"
#include <iostream>

int main(int argc, char **argv) {
  (void)argv;
  (void)argc;
  Data data = Data("John Smith", 35);
  std::cout << "Original attributes: " << std::endl
            << "data.getName() -> " << data.getName() << std::endl
            << "data.getAge() -> " << data.getAge() << std::endl;
  uintptr_t serialized = Serializer::serialize(&data);
  std::cout << std::endl
            << "Serialized: " << serialized << std::endl
            << std::endl;
  Data *deserialized = Serializer::deserialize(&serialized);
  std::cout << "Deserialized attributes: " << std::endl
            << "deserialized->getName() -> " << deserialized->getName()
            << std::endl
            << "deserialized->getAge() -> " << deserialized->getAge()
            << std::endl;
  return 0;
}
