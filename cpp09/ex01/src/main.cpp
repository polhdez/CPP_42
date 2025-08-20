#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

char getNextOp(string str) {
  static size_t i = 0;
  if (i >= str.length()) {
    return 0;
  }
  char c;
  size_t spacePos;
  if (!i) {
    c = str[0];
    i++;
  } else {
    spacePos = str.find(" ", i);
    if (str[spacePos + 2] && str[spacePos + 2] != ' ')
      return -1;
    c = str[spacePos + 1];
    i = spacePos + 2;
  }
  if (!(isdigit(c) || c == '*' || c == '/' || c == '-' || c == '+'))
    return -1;
  return c;
}

bool operate(stack<int> &s, char type) {
  if (s.size() == 1)
    return true;
  int op = s.top();
  s.pop();
  switch (type) {
  case '+':
    op = s.top() + op;
    break;
  case '-':
    op = s.top() - op;
    break;
  case '*':
    op = s.top() * op;
    break;
  case '/':
    op = s.top() / op;
    break;
  default:
    return false;
  }
  s.pop();
  s.push(op);
  return true;
}

int main(int argc, char **argv) {
  if (argc != 2)
    return 1;
  char c;
  stack<int> s;
  c = getNextOp(argv[1]);
  if (!c) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  while (c) {
    if (isdigit(c))
      s.push(c - '0');
    else {
      if (!operate(s, c)) {
        std::cerr << "Error" << std::endl;
        return 1;
      }
    }
    c = getNextOp(argv[1]);
    if (c == -1) {
      std::cerr << "Error" << std::endl;
      return 1;
    }
  }
  std::cout << s.top() << std::endl;
}
