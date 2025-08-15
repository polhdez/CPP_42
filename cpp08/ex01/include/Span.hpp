#pragma once
#include <exception>
#include <vector>

class Span : public std::vector<int> {
private:
  unsigned int _maxSize;
public:
  class FullSpanException : public std::exception {
    const char *what() const throw();
  };
  class NotEnoughValuesException : public std::exception {
    const char *what() const throw();
  };
  Span(unsigned int size);
  void addNumber(int n);
  void addNumbers(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end);
  int shortestSpan();
  int longestSpan();
};
