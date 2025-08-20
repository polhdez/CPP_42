#include "../include/RPN.hpp"
#include <iostream>

RPN::RPN() {};
RPN::RPN(const RPN &rpn) { (void)rpn; };
RPN::~RPN() {};
const RPN &RPN::operator=(const RPN &rpn) {
  (void)rpn;
  return *this;
};

char RPN::_getNextOp(string str) {
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

bool RPN::_operate(stack<int> &s, char type) {
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

bool RPN::calculate(string str) {
  char c;
  stack<int> s;
  c = _getNextOp(str);
  if (!c) {
    std::cerr << "Error" << std::endl;
    return false;
  }
  while (c) {
    if (isdigit(c))
      s.push(c - '0');
    else {
      if (!_operate(s, c)) {
        std::cerr << "Error" << std::endl;
        return false;
      }
    }
    c = _getNextOp(str);
    if (c == -1) {
      std::cerr << "Error" << std::endl;
      return false;
    }
  }
  std::cout << s.top() << std::endl;
  return true;
}
