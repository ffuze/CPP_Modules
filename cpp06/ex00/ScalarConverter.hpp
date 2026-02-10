#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits.h>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
    public:
        static void convert(const std::string& numeral);
};

enum ValueType
{
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	INVALID
};

ValueType findType(const std::string& value);

#endif