#include "BitcoinExchange.hpp"

#include <cstdio>

static bool writeTestFile(const std::string& filename, const std::string& content)
{
    std::ofstream output(filename.c_str());
    if (!output.is_open())
        return (false);
    output << content;
    return (true);
}

static void runSingleTest(const std::string& label, const std::string& filename,
    const std::string& content)
{
    std::cout << "\n=== " << label << " ===" << std::endl;
    if (!writeTestFile(filename, content))
    {
        std::cout << "Could not create test file: " << filename << std::endl;
        return ;
    }
    BitcoinExchange btc;
    if (!btc.manageFile(filename))
        std::cout << "manageFile() function failed" << std::endl;
    std::remove(filename.c_str());
}

static void runTests(void)
{
    runSingleTest(
        "Valid inputs",
        "test_valid_input.txt",
        "date | value\n"
        "2012-01-11 | 2\n"
        "2012-01-12 | 3\n"
        "2021-12-25 | 0.5\n"
    );
    runSingleTest(
        "Invalid inputs",
        "test_invalid_input.txt",
        "date | value\n"
        "2012-01-11 | -1\n"
        "2012-01-11 | 2147483648\n"
        "2001-42-42 | 5\n"
        "2012-01-11 5\n"
        "2008-12-31 | 1\n"
        "2012-01-11 | 4abc\n"
    );
    runSingleTest(
        "Provided sample",
        "test_sample_input.txt",
        "date | value\n"
        "2011-01-03 | 3\n"
        "2011-01-03 | 2\n"
        "2011-01-09 | 1\n"
        "2012-01-11 | -1\n"
        "2001-42-42\n"
        "2012-01-11 | 2147483648\n"
    );
}

int main(int argc, char *argv[])
{
    BitcoinExchange btc;

    if (argc == 1)
    {
        runTests();
        return (0);
    }
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <filename>" << std::endl;
        std::cout << "Run ./btc without arguments to execute built-in tests." << std::endl;
        return (0);
    }
    if (!btc.manageFile(argv[1]))
        std::cout << "manageFile() function failed" << std::endl;
    return (0);
}