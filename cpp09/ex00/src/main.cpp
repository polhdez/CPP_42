#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include "../include/BitcoinExchange.hpp"

using std::string;
/*
bool _isValidDate(const string &date) {
  // check date format (length position of - and if they are digits in correct
  // places)
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  for (int i = 0; i < 10; i++) {
    std::cout << date[i];
    if (i != 4 && i != 7 && !std::isdigit(date[i]))
      return false;
  }
  // num conversion
  int y, m, d;
  y = std::atoi(date.substr(0, 4).c_str());
  m = std::atoi(date.substr(5, 6).c_str());
  d = std::atoi(date.substr(8, 9).c_str());

  // Actually check if the dates are in the gregorian calendar
  // Reference from
  // http://www.zedwood.com/article/cpp-checkdate-function-date-validation
  if (!(1 <= m && m <= 12) || !(1 <= d && d <= 31))
    return false;
  if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
    return false;
  if ((d == 30) && (m == 2))
    return false;
  if ((m == 2) && (d == 29) && (y % 4 != 0))
    return false;
  if ((m == 2) && (d == 29) && (y % 400 == 0))
    return true;
  if ((m == 2) && (d == 29) && (y % 100 == 0))
    return false;
  if ((m == 2) && (d == 29) && (y % 4 == 0))
    return true;
  return true;
}
*/
int main() {
  BitcoinExchange be = BitcoinExchange("data.csv", "input.txt");
}
