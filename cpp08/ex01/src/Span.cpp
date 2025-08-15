#include "../include/Span.hpp"
#include <cstdlib>
#include <iterator>

// Custom exceptions

const char *Span::FullSpanException::what() const throw() {
  return "span is full!";
}

const char *Span::NotEnoughValuesException::what() const throw() {
  return "not enough values to calculate!";
}

Span::Span(unsigned int size) : _maxSize(size) {};

// Canonical stuff
void Span::addNumber(int n) {
  if (this->size() < _maxSize)
    this->push_back(n);
  else
    throw FullSpanException();
}

void Span::addNumbers(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) {
  if (std::distance(begin, end) + this->size() <= _maxSize)
    this->insert(this->end(), begin, end);
  else
    throw FullSpanException();
}

int Span::shortestSpan() {
  int small = 0;
  int absN;
  bool populated = false;
  if (this->size() < 2)
    throw NotEnoughValuesException();
  for (vector<int>::iterator firstIt = this->begin(); firstIt != this->end();
       firstIt++) {
    for (vector<int>::iterator secondIt = this->begin();
         secondIt != this->end(); secondIt++) {
      absN = std::abs(*firstIt - *secondIt);
      if (firstIt != secondIt && (!populated || absN < small)) {
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
  if (this->size() < 2)
    throw NotEnoughValuesException();
  for (vector<int>::iterator firstIt = this->begin(); firstIt != this->end();
       firstIt++) {
    for (vector<int>::iterator secondIt = this->begin();
         secondIt != this->end(); secondIt++) {
      absN = std::abs(*firstIt - *secondIt);
      if (firstIt != secondIt && (!populated || absN > big)) {
        big = absN;
        populated = true;
      }
    }
  }
  return big;
}
