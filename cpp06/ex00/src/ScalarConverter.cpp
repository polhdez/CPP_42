#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using std::numeric_limits;

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter &scalar) {
  (void)scalar;
};

const ScalarConverter &
ScalarConverter::operator=(const ScalarConverter &scalar) {
  (void)scalar;
  return *this;
};

ScalarConverter::~ScalarConverter(){};

void ScalarConverter::convert(const std::string &arg) {
  std::string str = arg;
  long long l;
  long double ld;
  string charStr, intStr, floatStr, doubleStr;
  std::stringstream ss("");

  // Nan and nanf specific case
  if (str == "nan" || str == "nanf") {
    charStr = "impossible";
    intStr = "impossible";
    float f = numeric_limits<float>::quiet_NaN();
    ss << f;
    floatStr = ss.str() + "f";
    ss.clear();
    ss.str("");
    double d = numeric_limits<double>::quiet_NaN();
    ss << d;
    doubleStr = ss.str();

    // Handle infinities
  } else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
    charStr = "impossible";
    intStr = "impossible";
    float f = numeric_limits<float>::infinity();
    ss << f << "f";
    floatStr = ss.str();
    ss.clear();
    ss.str("");
    double d = numeric_limits<double>::infinity();
    ss << d;
    doubleStr = ss.str();
  } else if (str == "-inf" || str == "-inff") {
    charStr = "impossible";
    intStr = "impossible";
    float f = -numeric_limits<float>::infinity();
    ss << f << "f";
    floatStr = ss.str();
    ss.clear();
    ss.str("");
    float d = -numeric_limits<double>::infinity();
    ss << d;
    doubleStr = ss.str();
  } else {

    // Not done yet, we have to prepare the input number and check it.

    // Remove trailing f if exists
    if (str[str.length() - 1] == 'f')
      str.resize(str.length() - 1);

    // check for valid input, handle neg and dots
    bool numOk = true;
    for (size_t i = 0; i < str.length(); i++) {
      if (i == 0 && str[i] == '-')
        i++;
      int ndots = 0;
      if (str[i] == '.') {
        ndots++;
        i++;
      }
      if (str[i] > '9' || str[i] < '0' || ndots > 1) {
        charStr = "impossible";
        intStr = "impossible";
        floatStr = "impossible";
        doubleStr = "impossible";
        numOk = false;
        break;
      }
    }

    // Everything is ok, NOW THE REAL THING
    if (numOk) {
      ss.clear();
      ss.str(str);
      ss >> l;

      // Uchar conversion so we can show the characters
      if (l <= numeric_limits<unsigned char>::max() &&
          l >= numeric_limits<unsigned char>::min()) {
        char c = static_cast<char>(l);
        if (std::isprint(c))
          charStr = c;
        else
          charStr = "Non displayable";
      } else
        charStr = "impossible";

      // Int conversion
      if (l <= numeric_limits<int>::max() && l >= numeric_limits<int>::min()) {
        ss.clear();
        ss.str("");
        int i = static_cast<int>(l);
        ss << i;
        intStr = ss.str();
      } else
        intStr = "impossible";

      // Fill a double double so we can work with floating point
      ss.clear();
      ss.str(str);
      ss >> ld;

      // Float conversion
      if (l <= numeric_limits<float>::max() &&
          l >= numeric_limits<float>::min()) {
        float f = static_cast<float>(ld);
        ss.clear();
        ss.str("");
        ss << std::fixed << std::setprecision(1) << f;
        floatStr = ss.str() + "f";
      } else
        floatStr = "impossible";

      // Double conversion
      if (l <= numeric_limits<double>::max() &&
          l >= numeric_limits<double>::min()) {
        double d = static_cast<double>(ld);
        ss.clear();
        ss.str("");
        ss << std::fixed << std::setprecision(1) << d;
        doubleStr = ss.str();
      } else
        doubleStr = "impossible";
    }
  }

  // Actually print this thing from nightmares
  std::cout << "char: " << charStr << std::endl;
  std::cout << "int: " << intStr << std::endl;
  std::cout << "float: " << floatStr << std::endl;
  std::cout << "double: " << doubleStr << std::endl;
}
