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

  // Nan and nanf specific case
  if (str == "nan") {
    std::cout << "char: impossible\n\
int: impossible\n\
float: nanf\n\
double: nan" << std::endl;
    return;
  }
// check for valid input, handle neg and dots
  for (size_t i = 0; i < str.length(); i++) {
      if (i == 0 && str[i] == '-')
          i++;
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
  // Convert to long long before anything to check limits
  std::stringstream ss(str);
  ss >> l;
  // Uchar conversion
  if (l <= UCHAR_MAX && l >= 0) {
    char c = (char)l;
    if (std::isprint(c))
      std::cout << "char: " << c << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else
    std::cout << "char: impossible" << std::endl;
  // Int conversion
  if ((l <= INT_MAX && l >= INT_MIN)) {
    int i = (int)l;
    std::cout << "int: " << i << std::endl;
  } else
    std::cout << "int: impossible" << std::endl;
  // Clear old stringstream
  ss.clear();
  ss.str(str);
  ss >> ld;
  // Float conversion
  if ((ld <= FLT_MAX && ld >= -FLT_MAX)) {
    float f = (float)ld;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f"
              << std::endl;
  } else
    std::cout << "float: impossible" << std::endl;
  // Double conversion
  if ((ld <= DBL_MAX && ld >= -DBL_MAX)) {
    double d = (double)ld;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d
              << std::endl;
  } else
    std::cout << "double: impossible" << std::endl;
}
