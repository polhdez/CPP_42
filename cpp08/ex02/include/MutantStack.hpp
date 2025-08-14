#pragma once
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  // Define underlying container iterator type as the new iterator
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  // calling this->c references to the base container class so we remap it to
  // the new iterator
  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
};
