#include "../include/Span.hpp"
#include <cstdlib>

// Custom exceptions

const char *Span::FullSpanException::what() const throw() {
  return "span is full!";
}

const char *Span::NotEnoughValuesException::what() const throw() {
  return "not enough values to calculate!";
}

// Canonical stuff

Span::Span(){};

Span::Span(unsigned int size) {
  _arrSize = size;
  _nItems = 0;
  _arr = new int[size];
}

Span::Span(const Span &span) {
  _arrSize = span._arrSize;
  _arr = new int[_arrSize];
  for (unsigned int i = 0; i < _arrSize; i++) {
    _arr[i] = span._arr[i];
  }
}

Span &Span::operator=(const Span &span) {
  if (this != &span) {
    delete[] _arr;
    _arrSize = span._arrSize;
    _arr = new int[_arrSize];
    for (unsigned int i = 0; i < _arrSize; i++) {
      _arr[i] = span._arr[i];
    }
  }
  return *this;
}

Span::~Span() { delete[] _arr; }

void Span::addNumber(int n) {
  if (_nItems >= _arrSize)
    throw FullSpanException();
  else
    _arr[_nItems++] = n;
}

// Methods

int Span::shortestSpan() {
  int small = 0;
  int absN;
  bool populated = false;
  if (_nItems < 2)
    throw NotEnoughValuesException();
  for (unsigned int i = 0; i < _nItems; i++) {
    for (unsigned int j = 0; j < _nItems; j++) {
      absN = std::abs(_arr[i] - _arr[j]);
      if (i != j && (!populated || absN < small)) {
        small = absN;
        populated = true;
      }
    }
  }
  return small;
}

int Span::longestSpan() {
  int big = 0;
  int absN;
  bool populated = false;
  if (_nItems < 2)
    throw NotEnoughValuesException();
  for (unsigned int i = 0; i < _nItems; i++) {
    for (unsigned int j = 0; j < _nItems; j++) {
      absN = std::abs(_arr[i] - _arr[j]);
      if (i != j && (!populated || absN > big)) {
        big = absN;
        populated = true;
      }
    }
  }
  return big;
}
