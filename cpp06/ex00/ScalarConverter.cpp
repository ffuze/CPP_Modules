#include "ScalarConverter.hpp"

static bool isChar(const std::string& value)
{
    if (value.length() == 3
        && value[0] == '\'' && value[2] == '\''
        && std::isprint(value[1]))
		{
			return (true);
		}
    if (value.length() == 1 && std::isprint(value[0]))
        return (true);
    return (false);
}

static bool isInt(const std::string& value)
{
	int start = 0;
	if (value.empty())
		return (false);
	if (value[0] == '+' || value[0] == '-')
		start = 1;
	for (size_t i = start; i < value.length(); i++)
	{
		if (!isdigit(value[i]))
			return (false);
	}
	return (true);
}

static bool isFloat(const std::string& value)
{
	if (value.empty() || value[value.length() - 1] != 'f')
        return (false);
    std::string fvalue = value.substr(0, value.length() - 1);
    if (fvalue == "nan" || fvalue == "-inf"
        || fvalue == "+inf" || fvalue == "inf")
        return (true);
    if (fvalue.find('.') == std::string::npos)
        return (false);
    char* end = 0;
    strtod(fvalue.c_str(), &end);
    if (end == fvalue.c_str() || *end != '\0')
        return (false);
    return (true);
}

static bool isDouble(const std::string& value)
{
	if (value.empty() || value[value.length() - 1] == 'f')
        return (false);
    if (value == "nan" || value == "-inf"
        || value == "+inf" || value == "inf")
        return (true);
    if (value.find('.') == std::string::npos)
        return (false);
    char* end = 0;
    strtod(value.c_str(), &end);
    if (end == value.c_str() || *end != '\0')
        return (false);
    return (true);
}


static void printInt(double value)
{
	std::cout << "int: ";
	int intvalue = static_cast<int>(value);
	if (std::isnan(intvalue) || std::isinf(intvalue))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	if (intvalue < INT_MIN || intvalue > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	else
		std::cout << static_cast<int>(intvalue) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
        float fval = static_cast<float>(value);
        std::cout << fval;
        if (fval == std::floor(fval) && fval >= -1e6 && fval <= 1e6)
        	std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
        std::cout << value;
        if (value == std::floor(value) && value >= -1e6 && value <= 1e6)
        	std::cout << ".0";
        std::cout << std::endl;
    }
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	int intvalue = static_cast<int>(value);
	if (intvalue < 0 || intvalue > 127)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	else if (!std::isprint(intvalue))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(intvalue) << std::endl;
}

ValueType findType(const std::string& value)
{
	if (isInt(value))
		return (INT);
	if (isFloat(value))
		return (FLOAT);
	if (isDouble(value))
		return (DOUBLE);
	if (isChar(value))
		return (CHAR);
	return (INVALID);
}

void ScalarConverter::convert(const std::string& value)
{
	ValueType type = findType(value);
	if (type == INVALID)
	{
		std::cout << "Invalid value passed" << std::endl;
		return;
	}
	double conv = 0;
	switch (type)
	{
		case INT:
			conv = static_cast<double>(strtol(value.c_str(), 0, 10));
            break;
		case FLOAT:
			{
				std::string fvalue = value.substr(0, value.length() - 1);
				conv = strtod(fvalue.c_str(), 0);
				break;
			}
		case DOUBLE:
			conv = strtod(value.c_str(), 0);
            break;
		case CHAR:
			if (value.length() == 1)
				conv = static_cast<double>(value[0]);
			if (value.length() == 3)
				conv = static_cast<double>(value[1]);
			break;
		default:
			break;
	}
	printChar(conv);
	printInt(conv);
	printFloat(conv);
	printDouble(conv);
}