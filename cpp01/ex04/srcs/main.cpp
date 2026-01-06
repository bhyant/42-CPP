#include <iostream>
#include <fstream>
#include <string>

std::string	replace_in_file(std::string line, std::string s1, std::string s2)
{
	if (s1.empty())
		return line;
	std::string	res = "";
	size_t	pos = 0;
	size_t	foundpos = line.find(s1, pos);

	while (foundpos != std::string::npos)
	{
		res += line.substr(pos, foundpos - pos);
		res += s2;
		pos = foundpos + s1.length();
		foundpos = line.find(s1, pos);
	}
	res += line.substr(pos);
	return res;
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Too many args" << std::endl, 1);
	std::ifstream file (av[1]);
	if (!file.is_open())
		return (std::cout << "File is not open" << std::endl, 1);
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string outFilename = std::string(av[1]) + ".replace";
	std::ofstream outfile(outFilename.c_str());
	if (!outfile.is_open())
	{
		file.close();
		return (std::cout << "Error creating output file" << std::endl, 1);
	}
	std::string	line;
	while (std::getline(file, line))
	{
		outfile << replace_in_file(line, s1, s2);
		if (!outfile.eof())
			outfile << std::endl;
	}
	file.close();
	outfile.close();
	return (0);
}
