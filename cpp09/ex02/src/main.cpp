#include "../include/PmergeMe.hpp"
#include <deque>
#include <vector>

using std::deque;
using std::vector;

int main(int argc, char **argv) {
  if (argc < 2) {
    return 1;
  }

  // Creating the containers using the static method.
  vector<int> intVec = argsToContainer<vector<int> >(argc, argv);
  deque<int> intDq = argsToContainer<deque<int> >(argc, argv);
  if ((int)intVec.size() != argc - 1  || (int)intDq.size() != argc - 1) {
    return 1;
  }
  PmergeMe<vector<int>, vector<vector<int> > > pmergeMeVec(intVec);
  PmergeMe<deque<int>, deque<deque<int> > > pmergeMeDeq(intDq);
}
