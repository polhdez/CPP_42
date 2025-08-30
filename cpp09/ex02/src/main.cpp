#include "../include/PmergeMe.hpp"
#include <deque>
#include <exception>
#include <vector>

using std::deque;
using std::vector;
typedef PmergeMe<vector<int>, vector<vector<int> > > PmergeMeVec;
typedef PmergeMe<deque<int>, deque<deque<int> > > PmergeMeDeq;

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
    intVec = PmergeMeVec::argsToContainer(argc, argv);
    intDeq = PmergeMeDeq::argsToContainer(argc, argv);
  } catch (std::exception &e) {
    std::cerr << "[!] Wrong input!" << std::endl;
    return 1;
  }

  // Execute functions and compare timestamps
  std::cout << "Processing vector..." << std::endl;
  long vecTime = timestamp();
  vector<int> sortedVec = PmergeMeVec::sort(intVec);
  vecTime = timestamp() - vecTime;
  PmergeMeVec::printContainer(sortedVec);
  std::cout << "Processing deque..." << std::endl;
  long deqTime = timestamp();
  deque<int> sortedDeq = PmergeMeDeq::sort(intDeq);
  deqTime = timestamp() - deqTime;
  PmergeMeDeq::printContainer(sortedDeq);
  std::cout << "[Benchmark] vector took " << vecTime << " µs" << std::endl;
  std::cout << "[Benchmark] deque  took " << deqTime << " µs" << std::endl;
}
