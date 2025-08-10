#include "../include/iter.hpp"
#include <string>

int main(void) {
    char charArr[] = {'a', 'b', 'c', 'd'};
    std::string strArr[] = {"str1", "str2", "str3", "str4"};
    int intArr[] = {1,2,3,4};
    ::iter(charArr, 4, ::argFun());
    ::iter(intArr, 4, ::argFun());
    ::iter(strArr, 4, ::argFun());
}
