// #include "../include/RPN.hpp"
#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

typedef vector<vector<int> > VecOfIntVec;

void printVecOfVec(VecOfIntVec vecOfVec) {
  std::cout << "[";
  for (VecOfIntVec::iterator vIt = vecOfVec.begin(); vIt != vecOfVec.end();
       ++vIt) {
    std::cout << "[";
    for (vector<int>::iterator it = vIt->begin(); it != vIt->end(); ++it) {
      std::cout << *it;
      if (std::next(it) != vIt->end())
        std::cout << ", ";
    }
    std::cout << "]";
    if (std::next(vIt) != vecOfVec.end())
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

bool argsToVec(int argc, char **argv, VecOfIntVec& vecOfVec) {
    for (int i = 1; i < argc; i++) {
      vector<int> vec;
      int n;
      std::stringstream ss(argv[i]);
      if (!(ss >> n))
        return false;
      vec.push_back(n);
      vecOfVec.push_back(vec);
    }
    return true;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    return 1;
  }
  VecOfIntVec vecOfVec;
  if (!argsToVec(argc, argv, vecOfVec))
      return 1;
  printVecOfVec(vecOfVec);
  return 0;
}
