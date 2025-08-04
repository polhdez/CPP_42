#include "../include/Data.hpp"

Data::Data(const string &name, const int &age) : _name(name), _age(age){};
Data::Data(const Data &data) {
  _name = data._name;
  _age = data._age;
};
const Data &Data::operator=(const Data &data) {
  if (this != &data) {
    _name = data._name;
    _age = data._age;
  }
  return *this;
}

Data::~Data(){};

const string &Data::getName() { return _name; }

const int &Data::getAge() { return _age; }
