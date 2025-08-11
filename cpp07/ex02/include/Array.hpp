#pragma once
#include <cstddef>
#include <exception>

template <typename T> class Array {
private:
  size_t _arrLen;
  T *_arr;

public:
  class OutOfBoundsException : public std::exception {
    const char *what() const throw() { return "Index out of bounds!"; }
  };
  Array() {
    _arr = new T[0];
    _arrLen = 0;
  }
  Array(size_t n) {
    _arr = new T[n];
    _arrLen = n;
  };

  Array(const Array &array) {
    _arrLen = array._arrLen;
    _arr = new T[_arrLen];
    for (size_t i = 0; i < _arrLen; i++)
      _arr[i] = array._arr[i];
  }

  ~Array() { delete[] _arr; }

  void operator=(const Array &array) {
    if (this != &array) {
      delete _arr;
      _arrLen = array._arrLen;
      _arr = new T[_arrLen];
      for (size_t i = 0; i < _arrLen; i++)
        _arr[i] = array._arr[i];
    }
  }

  T &operator[](size_t i) {
    if (i >= _arrLen)
      throw OutOfBoundsException();
    else
      return _arr[i];
  }
  size_t size() { return _arrLen; };
};
