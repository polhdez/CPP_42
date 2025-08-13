#include "../include/Span.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>

void printMsg(std::string msg) {
  std::cout << "\033[1;32m" << msg << "\033[0m" << std::endl;
}

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;
  std::stringstream ss(argv[1]);
  int nValues = 0;
  ss >> nValues;
  if (!nValues)
    return 1;
  // Seed randomness for testing
  std::srand(time(0));
  printMsg("Creating span");
  Span span(nValues);
  for (int i = 0; i < nValues; i++) {
    int randValue = std::rand() % 10;
    span.addNumber(randValue);
    std::cout << "Added n to span: " << randValue << std::endl;
  }
  printMsg("Running span methods");
  std::cout << "span.shortestSpan() -> " << span.shortestSpan() << std::endl;
  std::cout << "span.longestSpan() -> " << span.longestSpan() << std::endl;

  printMsg("Repeating after copy constructor: ");
  Span spanCopy(span);
  std::cout << "spanCopy.shortestSpan() -> " << span.shortestSpan()
            << std::endl;
  std::cout << "spanCopy.longestSpan() -> " << span.longestSpan() << std::endl;

  printMsg("Creating another span2 with random values:");
  Span span2(nValues);
  for (int i = 0; i < nValues; i++) {
    int randValue = std::rand() % 10;
    span2.addNumber(randValue);
    std::cout << "Added n to span2: " << randValue << std::endl;
  }
  printMsg("Running span2 methods: ");
  std::cout << "span2.shortestSpan() -> " << span2.shortestSpan() << std::endl;
  std::cout << "span2.longestSpan() -> " << span2.longestSpan() << std::endl;
  printMsg("Running methods after span=span2: ");
  span = span2;
  std::cout << "span.shortestSpan() -> " << span.shortestSpan() << std::endl;
  std::cout << "span.longestSpan() -> " << span.longestSpan() << std::endl;

  printMsg("Testing full span exception:");
  try {
    span.addNumber(1337);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  printMsg(
      "creating a span with only one number and trying to get span distances");
  Span singleSpan(1);
  singleSpan.addNumber(1337);
  try {
    singleSpan.longestSpan();
    singleSpan.shortestSpan();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
