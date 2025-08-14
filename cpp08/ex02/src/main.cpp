#include "../include/MutantStack.hpp"
#include <iostream>

void printMsg(std::string msg) {
  std::cout << "\033[1;32m" << msg << "\033[0m" << std::endl;
}

int main() {
    MutantStack<int> mutantStack;
    mutantStack.push(1);
    mutantStack.push(2);
    mutantStack.push(3);
    mutantStack.push(4);

    printMsg("Lets iterate our MutantStack!");
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
            std::cout << *it << std::endl;
    }
    printMsg("Lets test if it copies :)");
    MutantStack<int> mutantStackCopy(mutantStack);
    printMsg("Lets iterate our MutantStack copy!");
    for (MutantStack<int>::iterator it = mutantStackCopy.begin(); it != mutantStackCopy.end(); ++it) {
            std::cout << *it << std::endl;
    }
    printMsg("What about the =operator? Lets add 5 to the mutantStack copy");
    mutantStackCopy.push(5);
    printMsg("Now we set mutantStack=mutantStackCopy and we should have 5 inside");
    mutantStack=mutantStackCopy;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
            std::cout << *it << std::endl;
    }
  return 0;
}
