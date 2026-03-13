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

static bool isNegativeValue(double value)
{
	return (value < 0.0);
}

static bool isBiggerThanMAXINT(double value)
{
	return (value > 2147483647);
}

// handle negative values
// static bool isNegativeValue(const std::string value)
// {
// 	double conv_value = std::strtod(value.c_str(), NULL);
// 	std::cout << "Converted value: " << conv_value << std::endl;
// 	if (conv_value < 0.0)
// 		return (true);
// 	return (false);
// }


static void printErrorMessages(BitcoinExchange::ValueCases type)
{
	switch (type)
	{
		case BitcoinExchange::ERROR_NEGVALUE:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case BitcoinExchange::ERROR_MAXINT:
			std::cout << "Error: too large a number." << std::endl;
			break;
		case BitcoinExchange::ERROR_BADINPUT:
			std::cout << "Error: bad input => ";
			break;
		default:
			break;
	}
}
void BitcoinExchange::printMapContent(std::multimap<std::string, double> local_map) const
{
	BitcoinExchange::ValueCases type;
	for (std::multimap<std::string, double>::const_iterator it = local_map.begin(); it != local_map.end(); ++it)
	{
		if (isNegativeValue(it->second))
			type = BitcoinExchange::ERROR_NEGVALUE;
		if (isBiggerThanMAXINT(it->second))
			type = BitcoinExchange::ERROR_MAXINT;
		std::cout << it->first << " | " << it->second << "\n";
	}
	printErrorMessages(type);
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
		{
			std::cout << "Error: bad input => " << line.substr(0, line.size()) << std::endl;
			continue;
		}
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
	printMapContent(this->data);
	return (1);
}
