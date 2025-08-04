#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>

void ScalarConverter::convert(const std::string &arg) {
  std::string str = arg;
  long long l;
  long double ld;

  // Remove trailing f if exists
  if (str[str.length() - 1] == 'f')
    str.resize(str.length() - 1);

  if (str == "nan") {
    std::cout << "char: impossible\n\
int: impossible\n\
float: nanf\n\
double: nan" << std::endl;
    return;
  }

  for (size_t i = 0; i < str.length(); i++) {
    int ndots = 0;
    if (str[i] == '.') {
      ndots++;
      i++;
    }
    if (str[i] > '9' || str[i] < '0' || ndots > 1) {
      std::cout << "char: impossible\n\
int: impossible\n\
float: impossible\n\
double: impossible"
                << std::endl;
      return;
    }
  }
  std::stringstream ss(str);
  // Convert to long long before anything to check limits
  ss >> l;
  if (l <= CHAR_MAX && l >= CHAR_MIN) {
    char c = (char)l;
    if (std::isprint(c))
      std::cout << "char: " << c << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else
    std::cout << "char: impossible" << std::endl;
  if (l <= INT_MAX && l >= INT_MIN) {
    int i = (int)l;
    std::cout << "int: " << i << std::endl;
  } else
    std::cout << "int: impossible" << std::endl;
  ss.clear();
  ss.str(str);
  ss >> ld;
  if (ld <= FLT_MAX && ld >= FLT_MIN) {
    float f = (float)ld;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f"
              << std::endl;
  } else
    std::cout << "float: impossible" << std::endl;
  if (ld <= DBL_MAX && ld >= DBL_MIN) {
    double d = (double)ld;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d
              << std::endl;
  } else
    std::cout << "double: impossible" << std::endl;
}
