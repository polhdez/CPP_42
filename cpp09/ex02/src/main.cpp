// #include "../include/RPN.hpp"
#include <algorithm>
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

int jacobsthal(int n) {
    if (!n)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Redo this its ai powered
std::vector<int> getJacobsthalInsertionOrder(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (true) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n) break;
        jacobsthal.push_back(next);
    }

    // Build insertion order starting from largest Jacobsthal <= n
    std::vector<int> order;
    std::vector<bool> used(n, false);

    for (int i = (int)jacobsthal.size() - 1; i >= 0; --i) {
        int idx = jacobsthal[i];
        if (idx < n && !used[idx]) {
            order.push_back(idx);
            used[idx] = true;
        }
    }

    // Add remaining indices in ascending order
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            order.push_back(i);
            used[i] = true;
        }
    }

    return order;
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

    std::cout << "[*] Updated pairs: " << std::endl;
    printVecOfVec(pairs);
    if (extra != -1) {
        std::cout << "[*] Extra: " << std::endl;
        std::cout << extra << std::endl;
        newPend.push_back(extra);
    }
    if (newMain.size() > 1)
        mergeSort(newMain);

    main = newMain;

    vector<int> jacobSeq = getJacobsthalInsertionOrder(newPend.size());
    for (vector<int>::iterator it=jacobSeq.begin(); it != jacobSeq.end(); ++it) {
        vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), newPend[*it]);
        main.insert(pos, newPend[*it]);
    }
    std::cout << "Sorted!" << std::endl;
    printVec(main);

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
