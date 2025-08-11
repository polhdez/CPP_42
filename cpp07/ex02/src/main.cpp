#include "../include/Array.hpp"
#include <exception>
#include <iostream>
#include <string>

using std::string;

void printMsg(string msg) {
  std::cout << "\033[1;32m" << msg << "\033[0m" << std::endl;
}

int main(void) {
  printMsg("Creating Array<char>");
  Array<char> arrChar = Array<char>(4);
  arrChar[0] = 'a';
  arrChar[1] = 'b';
  arrChar[2] = 'c';
  arrChar[3] = 'd';
  printMsg("Printing values from array<char>");
  for (size_t i = 0; i < arrChar.size(); i++)
    std::cout << arrChar[i] << std::endl;
  printMsg("Creating Array<std::string>");
  Array<string> arrStr = Array<string>(4);
  arrStr[0] = "first";
  arrStr[1] = "second";
  arrStr[2] = "third";
  arrStr[3] = "fourth";
  printMsg("Printing values from array<std::string>");
  for (size_t i = 0; i < arrStr.size(); i++)
    std::cout << arrStr[i] << std::endl;
  printMsg("Copying array");
  Array<string> arrStrCpy = Array<string>(arrStr);
  printMsg("Printing contents from copied array");
  for (size_t i = 0; i < arrStrCpy.size(); i++)
    std::cout << arrStrCpy[i] << std::endl;
  printMsg("Trying reading out of bounds");
  try {
    std::cout << arrStrCpy[4] << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception e.what(): " << e.what() << std::endl;
  }
  printMsg("Trying writing out of bounds");
  try {
    arrStrCpy[4] = "this is a test";
  } catch (std::exception &e) {
    std::cout << "Exception e.what(): " << e.what() << std::endl;
  }
  return 0;
}
