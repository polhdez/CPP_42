#include "../include/easyfind.hpp"
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;
  std::stringstream ss(argv[1]);
  int n, ret;
  ss >> n;
  std::list<int> nList;
  nList.push_back(1);
  nList.push_back(2);
  nList.push_back(3);
  nList.push_back(4);
  nList.push_back(5);
  try {
    ret = ::easyFind(nList, n);
    std::cout << "easyFind ret value from list<int>: " << ret << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << " " << n << "value not found" << std::endl;
  }
  std::vector<int> nVec;
  nVec.push_back(1);
  nVec.push_back(2);
  nVec.push_back(3);
  nVec.push_back(4);
  nVec.push_back(5);
  try {
    ret = ::easyFind(nList, n);
    std::cout << "easyFind ret value from vector<int>: " << ret << std::endl;
  } catch (std::exception &e) {
      std::cout << e.what() << " " << n << "value not found" << std::endl;
  }
  return 0;
}
