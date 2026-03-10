#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <stdlib.h>
# include <string>
# include <fstream>
# include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        // open file passed as argumetn in argv, then read and store every line into the map
        int manageFile(std::string local_database);
              
};

#endif