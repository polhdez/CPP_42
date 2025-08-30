#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <sys/time.h>

template <typename C, typename CC> class PmergeMe {

private:
  static int _jacobsthal(int n) {
    if (!n)
      return 0;
    if (n == 1)
      return 1;
    return _jacobsthal(n - 1) + 2 * _jacobsthal(n - 2);
  }

  static C _genJacobSeq(int n) {
    C jacobSeq;

    jacobSeq.push_back(0);
    jacobSeq.push_back(1);
    int next = 2;
    do {
      jacobSeq.push_back(next);
      next = jacobSeq[jacobSeq.size() - 1] + 2 * jacobSeq[jacobSeq.size() - 2];
    } while (next < n);
    return jacobSeq;
  }

  static C _getJacobsthalInsertionOrder(int n, C jacobSeq) {
    // Add first the jacob numbers to order
    C order;
    for (typename C::reverse_iterator it = jacobSeq.rbegin();
         it != jacobSeq.rend(); ++it) {using std::string;
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

  static C _mergeInsertionSort(C &main, const C &jacobSeq) {
    CC pairs;
    int extra = -1;
    typename C::iterator vecEnd = main.end();

    // If the list is odd set the extra variable with the last number
    // merge just works with pairs so we will need it later
    if (main.size() % 2) {
      extra = main.back();
      vecEnd--;
    }
    // Sort the pairs with the smallest int first in each pair. format [ [1,2], [3,4]... ]
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

    // Reset the main container and create the pend list (mindfuck)
    C pend;
    main.clear();
    for (typename CC::iterator it = pairs.begin(); it != pairs.end(); ++it) {
      main.push_back(it->back());
      pend.push_back(it->front());
    }

    // The flag for extra is just -1 (ugly)
    if (extra != -1) {
      pend.push_back(extra);
    }
    // Do it recursively until theres just one number
    if (main.size() > 1)
      _mergeInsertionSort(main, jacobSeq);

    // Do the insertions based on the jacobsthal sequence
    C insertOrder = _getJacobsthalInsertionOrder(pend.size(), jacobSeq);
    for (typename C::iterator it = insertOrder.begin(); it != insertOrder.end();
         ++it) {
      typename C::iterator pos =
          std::lower_bound(main.begin(), main.end(), pend.at(*it));
      main.insert(pos, pend.at(*it));
    }
    return main;
  }

  // Prevent instantiation setting the default constructor private
  PmergeMe() {};

public:
  static void printContainer(C vec) {
    std::cout << "[";
    for (typename C::iterator it = vec.begin(); it != vec.end(); ++it) {
      std::cout << *it;
      if (it + 1 != vec.end())
        std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }

  static C sort(C vec) {
    // Precalculate jacob sequence to avoid recalculating each iteration
    C jacobSeq = _genJacobSeq(vec.size());
    // Do eet
    return _mergeInsertionSort(vec, jacobSeq);
  }

  static C argsToContainer(int argc, char **argv) {
    C vec;
    for (int i = 1; i < argc; i++) {
      int n;
      std::stringstream ss(argv[i]);
      if (!(ss >> n))
        throw std::exception();
      vec.push_back(n);
    }
    return vec;
  }
};
