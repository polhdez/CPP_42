// #include "../include/RPN.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using std::string;
using std::vector;

typedef vector<vector<int> > VecOfIntVec;

void printVec(vector<int> vec) {
  std::cout << "[";
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it;
    if (it + 1 != vec.end())
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

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

int getBiggestFromVec(vector<int> vec) {
  int big = 0;
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    if (*it > big)
      big = *it;
  }
  return big;
}

void processMainPend(VecOfIntVec &main, VecOfIntVec &pend, vector<int> &wait) {
  VecOfIntVec newMain;
  VecOfIntVec newPend;
  vector<int> newWait;

  int elementMainSize = main.front().size() / 2;
  for (int i = 0; i < main.size(); i++) {
    vector<int> splitVecOne;
    vector<int> splitVecTwo;
    for (int j = 0; j < main[i].size(); j++) {
      if (j < elementMainSize)
        splitVecOne.push_back(main[i][j]);
      else
        splitVecTwo.push_back(main[i][j]);
    }
    if (i == 0) {
        newMain.push_back(splitVecOne);
        newMain.push_back(splitVecTwo);
    } else {
        newPend.push_back(splitVecOne);
        newMain.push_back(splitVecTwo);
    }
  }
  if (wait.size() >= elementMainSize) {
      vector<int> elementFromWait;
      elementFromWait.insert(elementFromWait.end(), wait.begin(), wait.begin() + elementMainSize);
      newPend.push_back(elementFromWait);
      newWait.insert(newWait.end(), wait.begin() + elementMainSize, wait.end());
  }
  main = newMain;
  pend = newPend;
  wait = newWait;
}

void mergeSort(VecOfIntVec &vecOfVec) {
  bool remain;
  int nMerges;
  int order = 1;
  int halfListSize = vecOfVec.size() / 2;
  // Merge sort until the first sublist is bigger than the amount of numbers
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
      if (getBiggestFromVec(vecOfVec[i]) > getBiggestFromVec(vecOfVec[i + 1]) &&
          vecOfVec[i].size() == vecOfVec[i + 1].size())
        std::swap(vecOfVec[i], vecOfVec[i + 1]);
      vector<int> tmp = vecOfVec[i];
      tmp.insert(tmp.end(), vecOfVec[i + 1].begin(), vecOfVec[i + 1].end());
      newVecOfVec.push_back(tmp);
    }
    if (remain)
      newVecOfVec.push_back(vecOfVec.back());
    vecOfVec = newVecOfVec;
  } while (vecOfVec.front().size() * 2 < halfListSize);
  std::cout << "After merge sort" << std::endl;
  printVecOfVec(vecOfVec);
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
