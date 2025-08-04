#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <string>

using std::string;

class ScalarConverter {
private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter &scalar);
  const ScalarConverter &operator=(const ScalarConverter &scalar);
  ~ScalarConverter();

public:
  static void convert(const string &str);
};
#endif
