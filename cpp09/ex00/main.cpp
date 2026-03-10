#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    BitcoinExchange btc;
    if (argc != 2)
    {
        std::cout << "Input format should be as follows: ./btc <filename>" << std::endl;
        return (0);
    }
    if (!btc.manageFile(argv[1]))
        std::cout << "manageFile() function failed" << std::endl;
    return (0);
}