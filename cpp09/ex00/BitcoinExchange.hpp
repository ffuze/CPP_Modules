#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <fstream>
# include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> rates;
        static std::string trim(const std::string& value);
        static bool isLeapYear(int year);
        static bool isValidDate(const std::string& date);
        static bool parseValue(const std::string& valueStr, double& value);
        bool loadDatabase(const std::string& databaseFile);
        double getRateForDate(const std::string& date) const;
        void processInputLine(const std::string& line) const;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        int manageFile(std::string inputFile);
        enum ValueCases
        {
            ERROR_MAXINT,
            ERROR_NEGVALUE,
            ERROR_BADINPUT // needs to be extended once all the parsing details will be handled
        };
};

#endif