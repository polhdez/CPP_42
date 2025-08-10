#include "../include/Array.hpp"
#include <iostream>

int main(void) {
    Array<char> arrChar = Array<char>(4);
    arrChar[0] = 'a';
    arrChar[1] = 'b';
    arrChar[2] = 'c';
    arrChar[3] = 'd';
    for (size_t i=0; i < 4; i++)
        std::cout << arrChar[i] << std::endl;
    Array<std::string> arrStr = Array<std::string>(4);
    arrStr[0] = "first";
    arrStr[1] = "second";
    arrStr[2] = "third";
    arrStr[3] = "fourth";
    for (size_t i=0; i < 4; i++)
        std::cout << arrStr[i] << std::endl;
    return 0;
}
