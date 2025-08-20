#include "../include/RPN.hpp"

using std::string;

int main(int argc, char **argv) {
    if (argc!=2) {
        return 1;
    }
    RPN rpn;
    if(!rpn.calculate(argv[1]))
        return 1;
    return 0;
}
