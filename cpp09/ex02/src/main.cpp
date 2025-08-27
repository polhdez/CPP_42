// #include "../include/RPN.hpp"
#include <iostream>
#include <sstream>
#include <utility>
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
      if (it + 1 != vIt->end())
        std::cout << ", ";
    }
    std::cout << "]";
    if (vIt + 1 != vecOfVec.end())
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

void mergeSort(VecOfIntVec &vecOfVec) {

  // Initialize values so we work with even numbers while merging
  bool remain;
  int nMerges;

  // Merge mindfuck
  do {
      printVecOfVec(vecOfVec);
    if (vecOfVec.size() % 2) {
      nMerges = vecOfVec.size() - 1;
      remain = true;
    } else {
      nMerges = vecOfVec.size();
      remain = false;
    }
    VecOfIntVec newVecOfVec;
    for (int i = 0; i < nMerges; i += 2) {
      if (vecOfVec[i].back() > vecOfVec[i + 1].front())
        std::swap(vecOfVec[i], vecOfVec[i + 1]);
      vector<int> tmp = vecOfVec[i];
      tmp.insert(tmp.end(), vecOfVec[i + 1].begin(), vecOfVec[i + 1].end());
      newVecOfVec.push_back(tmp);
    }
    if (remain)
      newVecOfVec.push_back(vecOfVec.back());
    vecOfVec = newVecOfVec;
  } while (nMerges > 0);
}

bool argsToVec(int argc, char **argv, VecOfIntVec &vecOfVec) {
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
  mergeSort(vecOfVec);
  return 0;
}
