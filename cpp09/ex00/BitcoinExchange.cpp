#include "BitcoinExchange.hpp"

#include <cctype>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		rates = copy.rates;
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
	return (value > 2147483647.0);
}

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

std::string BitcoinExchange::trim(const std::string& value)
{
	std::string::size_type start = value.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	std::string::size_type end = value.find_last_not_of(" \t");
	return (value.substr(start, end - start + 1));
}

bool BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (std::string::size_type i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool BitcoinExchange::parseValue(const std::string& valueStr, double& value)
{
	char *endPtr = NULL;
	value = std::strtod(valueStr.c_str(), &endPtr);
	if (endPtr == valueStr.c_str())
		return (false);
	while (*endPtr != '\0')
	{
		if (!std::isspace(static_cast<unsigned char>(*endPtr)))
			return (false);
		++endPtr;
	}
	return (true);
}

bool BitcoinExchange::loadDatabase(const std::string& databaseFile)
{
	std::ifstream database(databaseFile.c_str());
	if (!database.is_open())
	{
		std::cout << "Error: could not open database." << std::endl;
		return (false);
	}
	std::string line;
	bool firstLine = true;
	while (std::getline(database, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		if (line.empty())
			continue;
		std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = trim(line.substr(0, comma));
		std::string rateStr = trim(line.substr(comma + 1));
		double rate = 0.0;
		if (!isValidDate(date) || !parseValue(rateStr, rate))
			continue;
		rates[date] = rate;
	}
	if (rates.empty())
	{
		std::cout << "Error: database is empty or invalid." << std::endl;
		return (false);
	}
	return (true);
}

double BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = rates.lower_bound(date);
	if (it != rates.end() && it->first == date)
		return (it->second);
	if (it == rates.begin())
		throw std::runtime_error("Error: no rate available for this date.");
	--it;
	return (it->second);
}

void BitcoinExchange::processInputLine(const std::string& line) const
{
	std::string::size_type pipe = line.find('|');
	if (pipe == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::string date = trim(line.substr(0, pipe));
	std::string valueStr = trim(line.substr(pipe + 1));
	double value = 0.0;
	if (!isValidDate(date) || !parseValue(valueStr, value))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (isNegativeValue(value))
	{
		printErrorMessages(BitcoinExchange::ERROR_NEGVALUE);
		return ;
	}
	if (isBiggerThanMAXINT(value))
	{
		printErrorMessages(BitcoinExchange::ERROR_MAXINT);
		return ;
	}
	try
	{
		double rate = getRateForDate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}
}

int BitcoinExchange::manageFile(std::string inputFile)
{
	if (inputFile.empty())
		return (0);
	if (!loadDatabase("data.csv"))
		return (0);
	std::ifstream inputBuffer(inputFile.c_str());
	if (!inputBuffer.is_open())
		return (0);
	std::string line;
	bool firstLine = true;
	while (std::getline(inputBuffer, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		if (line.empty())
			continue;
		processInputLine(line);
	}
	return (1);
}
