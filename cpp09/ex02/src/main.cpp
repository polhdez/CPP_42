// #include "../include/RPN.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using std::string;
using std::vector;

//typedef vector<vector<int> > VecOfIntVec;

void printVec(vector<int> vec) {
  std::cout << "[";
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it;
    if (it + 1 != vec.end())
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

void printVecOfVec(vector<vector<int> > vecOfVec) {
  std::cout << "[";
  for (vector<vector<int> >::iterator vIt = vecOfVec.begin(); vIt != vecOfVec.end();
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

void mergeSort(vector<int>& main) {
    vector<vector<int> > pairs;

    int extra = -1;
    vector<int>::iterator vecEnd = main.end();

    if (main.size() % 2) {
        extra = main.back();
        vecEnd--;
    }
    for (vector<int>::iterator it = main.begin(); it != vecEnd; it += 2) {
        vector<int>::iterator nextIt = it + 1;
        vector<int> pair;
        pair.push_back(*it);
        if (*it < *nextIt)
            pair.push_back(*nextIt) ;
        else
            pair.insert(pair.begin(), *nextIt) ;
        pairs.push_back(pair);
    }
    vector<int> newMain;
    vector<int> newPend;
    for (vector<vector<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        newMain.push_back(it->back());
        newPend.push_back(it->front());
    }

    if (extra != -1) {
        std::cout << "[*] Extra: " << std::endl;
        std::cout << extra << std::endl;
    }
    std::cout << "[*] Updated pairs: " << std::endl;
    printVecOfVec(pairs);
    std::cout << "[*] newMain: " << std::endl;
    printVec(newMain);
    std::cout << "[*] newPend: " << std::endl;
    printVec(newPend);
    if (newMain.size() > 1)
        mergeSort(newMain);
}

bool argsToVec(int argc, char **argv, vector<int> &vec) {
  for (int i = 1; i < argc; i++) {
    int n;
    std::stringstream ss(argv[i]);
    if (!(ss >> n))
      return false;
    vec.push_back(n);
  }
  return true;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    return 1;
  }
  vector<int> vec;
  if (!argsToVec(argc, argv, vec))
    return 1;
  mergeSort(vec);
  return 0;
}
