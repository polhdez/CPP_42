#pragma once
#include <iostream>

// Using a functor so we can actually use a function with template as args
struct argFun {
    public:
    template <typename T> void operator() (T t) const {
        std::cout << "Argument function called with this value: " << t << std::endl;
    }
};

template <typename T, typename Fun> void iter(T* arr, size_t size, Fun fun) {
    for (size_t i=0; i<size; i++) {
        fun(arr[i]);
    }
}
