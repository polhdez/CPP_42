#include "../include/BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

using std::string;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " input.txt" << std::endl;
        return 1;
    }
  BitcoinExchange be = BitcoinExchange("data.csv", argv[1]);
}
