#include "../include/PmergeMe.hpp"
#include <deque>
#include <exception>
#include <vector>

using std::deque;
using std::vector;

long timestamp() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    return 1;
  }

  // Here we parse the input and put it into both types of containers
  vector<int> intVec;
  deque<int> intDeq;
  try {
    intVec = PmergeMe<vector<int> >::argsToContainer(argc, argv);
    intDeq = PmergeMe<deque<int> >::argsToContainer(argc, argv);
  } catch (std::exception &e) {
    std::cerr << "[!] Wrong input!" << std::endl;
    return 1;
  }

  // Execute functions and compare timestamps
  std::cout << "Processing vector..." << std::endl;
  long vecTime = timestamp();
  vector<int> sortedVec = PmergeMe<vector<int> >::sort(intVec);
  vecTime = timestamp() - vecTime;
  PmergeMe<vector<int> >::printContainer(sortedVec);
  std::cout << "Processing deque..." << std::endl;
  long deqTime = timestamp();
  deque<int> sortedDeq = PmergeMe<deque<int> >::sort(intDeq);
  deqTime = timestamp() - deqTime;
  PmergeMe<deque<int> >::printContainer(sortedDeq);
  std::cout << "[Benchmark] vector took " << vecTime << " µs" << std::endl;
  std::cout << "[Benchmark] deque  took " << deqTime << " µs" << std::endl;
}
