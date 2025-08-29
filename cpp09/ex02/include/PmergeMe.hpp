#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>

using std::string;

template <typename C, typename CC> class PmergeMe {
private:
  void _printVec(C vec);
  void _printVecOfVec(CC vecOfVec);
  int _jacobsthal(int n);
  C _getJacobsthalInsertionOrder(int n);
  void _mergeInsertionSort(C &main);

public:
PmergeMe();
PmergeMe(C vec);
~PmergeMe();
PmergeMe(const PmergeMe &pmergeMe);
PmergeMe &operator=(const PmergeMe& pmergeMe);
};

template <typename C, typename CC>
void PmergeMe<C,CC>::_printVec(C vec) {
  std::cout << "[";
  for (typename C::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it;
    if (it + 1 != vec.end())
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

template <typename C, typename CC>
void PmergeMe<C,CC>::_printVecOfVec(CC vecOfVec) {
  std::cout << "[";
  for (typename CC::iterator vIt = vecOfVec.begin();
       vIt != vecOfVec.end(); ++vIt) {
    std::cout << "[";
    for (typename C::iterator it = vIt->begin(); it != vIt->end();
         ++it) {
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

template <typename C, typename CC> int PmergeMe<C, CC>::_jacobsthal(int n) {
  if (!n)
    return 0;
  if (n == 1)
    return 1;
  return _jacobsthal(n - 1) + 2 * _jacobsthal(n - 2);
}

template <typename C, typename CC>
C PmergeMe<C, CC>::_getJacobsthalInsertionOrder(int n) {
  C jacobSeq;

  jacobSeq.push_back(0);
  jacobSeq.push_back(1);
  int next = 2;
  do {
    jacobSeq.push_back(next);
    next = jacobSeq[jacobSeq.size() - 1] + 2 * jacobSeq[jacobSeq.size() - 2];
  } while (next < n);

  // Add first the jacob numbers to order
  C order;
  for (typename C::reverse_iterator it = jacobSeq.rbegin();
       it != jacobSeq.rend(); ++it) {
    if (*it < n)
      order.push_back(*it);
  }

  // Add remaining indices to order
  for (int i = 0; i < n; ++i) {
    if (std::find(jacobSeq.begin(), jacobSeq.end(), i) == jacobSeq.end())
      order.push_back(i);
  }

  return order;
}

template <typename C, typename CC>
void PmergeMe<C,CC>::_mergeInsertionSort(C &main) {
  CC pairs;

  int extra = -1;
  typename C::iterator vecEnd = main.end();

  if (main.size() % 2) {
    extra = main.back();
    vecEnd--;
  }
  for (typename C::iterator it = main.begin(); it != vecEnd; it += 2) {
    typename C::iterator nextIt = it + 1;
    C pair;
    pair.push_back(*it);
    if (*it < *nextIt)
      pair.push_back(*nextIt);
    else
      pair.insert(pair.begin(), *nextIt);
    pairs.push_back(pair);
  }
  C newMain;
  C newPend;
  for (typename CC::iterator it = pairs.begin();
       it != pairs.end(); ++it) {
    newMain.push_back(it->back());
    newPend.push_back(it->front());
  }

  std::cout << "[*] Updated pairs: " << std::endl;
  _printVecOfVec(pairs);
  if (extra != -1) {
    std::cout << "[*] Extra: " << std::endl;
    std::cout << extra << std::endl;
    newPend.push_back(extra);
  }
  if (newMain.size() > 1)
    _mergeInsertionSort(newMain);
  main = newMain;
  C jacobSeq = _getJacobsthalInsertionOrder(newPend.size());
  for (typename C::iterator it = jacobSeq.begin(); it != jacobSeq.end();
       ++it) {
    typename C::iterator pos =
        std::lower_bound(main.begin(), main.end(), newPend.at(*it));
    main.insert(pos, newPend.at(*it));
  }
  std::cout << "Sorted!" << std::endl;
  _printVec(main);
}
template <typename C, typename CC> PmergeMe<C,CC>::~PmergeMe(){};

template <typename C, typename CC> PmergeMe<C,CC>::PmergeMe() {};

template <typename C, typename CC> PmergeMe<C,CC>::PmergeMe(C vec) {
  _mergeInsertionSort(vec);
}

template <typename C, typename CC>
PmergeMe<C,CC> &PmergeMe<C,CC>::operator=(const PmergeMe &be) {
  return *this;
}

template <typename C> C argsToContainer(int argc, char **argv) {
  C vec;
  for (int i = 1; i < argc; i++) {
    int n;
    std::stringstream ss(argv[i]);
    if (!(ss >> n))
      return vec;
    vec.push_back(n);
  }
  return vec;
}


template <typename C> C argsToContainer(int argc, char **argv);
