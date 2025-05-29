#include <iostream>

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string    value:" << string << " string     address:" << &string << "\n";
	std::cout << "stringPTR value:" << *stringPTR << " stringPTR address: " << &stringPTR << "\n";
	std::cout << "stringREF value:" << stringREF << " stringREF address: " << &stringREF << "\n";
	return (0);
}
