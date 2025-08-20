#pragma once
#include <string>
#include <stack>

using std::string;
using std::stack;

class RPN {
    private:
    char _getNextOp(string str);
    bool _operate(stack<int> &s, char type);
    public:
    RPN();
    RPN(string str);
    RPN(const RPN& rpn);
    const RPN& operator=(const RPN& rpn);
    ~RPN();
    bool calculate(string s);
};
