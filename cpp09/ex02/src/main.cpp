#include "../include/PmergeMe.hpp"
#include <deque>
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

  // Creating the containers using the static method.
  vector<int> intVec = argsToContainer<vector<int> >(argc, argv);
  deque<int> intDq = argsToContainer<deque<int> >(argc, argv);
  if ((int)intVec.size() != argc - 1 || (int)intDq.size() != argc - 1) {
    return 1;
  }
  std::cout << "Processing vector..." << std::endl;
  long vecTime = timestamp();
  PmergeMe<vector<int>, vector<vector<int> > > pmergeMeVec(intVec);
  vecTime = timestamp() - vecTime;
  std::cout << "Processing deque..." << std::endl;
  long deqTime = timestamp();
  PmergeMe<deque<int>, deque<deque<int> > > pmergeMeDeq(intDq);
  deqTime = timestamp() - deqTime;
  std::cout << "[Benchmark] vector took " << vecTime << " µs" << std::endl;
  std::cout << "[Benchmark] deque  took " << deqTime << " µs" << std::endl;
}
