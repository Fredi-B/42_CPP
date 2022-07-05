#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string		infile_name;
	std::string		outfile_name;
	std::string		s1;
	std::string 	s2;
	std::string 	buffer;
	std::size_t		pos_of_match;

	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	infile_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	outfile_name = infile_name;
	outfile_name.append(".replace");

	std::ifstream	infile(infile_name);
	if (infile.fail())
	{
		std::cout << "Errorr: Could not open infile: " << infile_name << std::endl;
		return (1);
	}
	std::ofstream	outfile(outfile_name);
	if (outfile.fail())
	{
		std::cout << "Errorr: Could not open outfile: " << outfile_name << std::endl;
		return (1);
	}

	while(!infile.eof())
	{
		getline(infile, buffer);
		while ((pos_of_match = buffer.find(s1)) != std::string::npos)
		{
			buffer.erase(pos_of_match, s1.length());
			buffer.insert(pos_of_match, s2);
		}
		outfile << buffer;
		if (infile.eof())
			break ;
		outfile << std::endl;
	}
	outfile.close();
	infile.close();
}
