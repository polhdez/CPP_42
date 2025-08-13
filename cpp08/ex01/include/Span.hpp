#pragma once
#include <exception>

class Span {
private:
  int *_arr;
  unsigned int _arrSize;
  unsigned int _nItems;
  Span();
public:
  class FullSpanException : public std::exception {
    const char *what() const throw();
  };
  class NotEnoughValuesException : public std::exception {
    const char *what() const throw();
  };
  Span(unsigned int size);
  Span(const Span &span);
  Span &operator=(const Span &span);
  ~Span();
  void addNumber(int n);
  int shortestSpan();
  int longestSpan();
};
