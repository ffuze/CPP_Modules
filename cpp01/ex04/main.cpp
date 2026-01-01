#include <iostream>
#include <fstream>

int replaceAll(std::string filename, std::string s1, std::string s2)
{
	std::string ifbuffer;
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Empty or incorrect value was passed" << std::endl;
		return (0);
	}
	std::ifstream ifile(filename.c_str());
	if (!ifile.is_open())
	{
		std::cout << "File cannot be open" << std::endl;
		return (0);
	}
	std::ofstream newfile((std::string(filename + ".replace")).c_str());
	if (!newfile.is_open())
	{
		std::cout << "New file cannot be created" << std::endl;
		return (0);
	}
	std::string line;
	bool firstline = true;
    while (std::getline(ifile, line))
    {
		if (!firstline)
			newfile << '\n';
		firstline = false;
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        newfile << line;
    }
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (!replaceAll(argv[1], argv[2], argv[3]))
		return (0);
}