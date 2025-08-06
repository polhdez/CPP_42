#pragma once
#include <string>
using std::string;

class Data {
private:
  string _name;
  int _age;

public:
  Data(const string &name, const int &age);
  Data(const Data &data);
  const Data &operator=(const Data &data);
  ~Data();

  const string &getName();
  const int &getAge();
};
