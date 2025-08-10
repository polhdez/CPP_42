#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T> class Array {
private:
  size_t _arrLen;
  T *_arr;

public:
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
      throw std::exception();
    else
      return _arr[i];
  }

  size_t size() { return _arrLen; };
};
