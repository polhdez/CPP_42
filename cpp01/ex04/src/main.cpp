#include "../includes/main.hpp"

int main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		str;
	std::string		new_str;
	std::string		line;
	std::size_t		found;
	std::string		new_line;
	std::string		filename;

	if (argc < 4)
		return(1);
	str = argv[2];
	new_str = argv[3];
	filename = argv[1];
	infile.open(filename.c_str());
	filename = filename + ".replace";
	outfile.open(filename.c_str());
	while (!infile.eof())
	{
		std::getline(infile, line);
		found = line.find(str);
		while (found != std::string::npos)
		{
			new_line = line.substr(0, found) + new_str + line.substr(found + str.length());
			line = new_line;
			found = line.find(str, found);
		}
		outfile << line;
		if (!infile.eof())
			outfile << '\n';
	}
	outfile.close();
	return (0);
}
