#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		this->data = copy.data;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->operator=(copy);
}

int BitcoinExchange::manageFile(std::string local_database)
{
	if (local_database.empty())
		return (0);
	std::ifstream input_buffer(local_database.c_str());
	if (!input_buffer.is_open())
		return (0);
	std::string line;
	bool firstline = true;
	while (std::getline(input_buffer, line))
	{
		// skip header line
		if (firstline)
		{
			firstline = false;
			continue;
		}
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
			continue;
		std::string date = line.substr(0, pipe);
		std::string valueStr = line.substr(pipe + 1);
		// trim trailing spaces from date
		size_t end = date.find_last_not_of(" \t");
		if (end != std::string::npos)
			date = date.substr(0, end + 1);
		// trim leading spaces from value
		size_t start = valueStr.find_first_not_of(" \t");
		if (start != std::string::npos)
			valueStr = valueStr.substr(start);
		double value = std::strtod(valueStr.c_str(), NULL);
		this->data.insert(std::pair<std::string, double>(date, value));
	}
	return (1);
}