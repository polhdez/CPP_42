#pragma once
#include <algorithm>
#include <exception>

template <typename T> int easyFind(const T &container, int n) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), n);
  if (it != container.end())
    return *it;
  throw std::exception();
}
