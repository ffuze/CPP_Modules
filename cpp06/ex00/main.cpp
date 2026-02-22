# include "ScalarConverter.hpp"

static void runTest(const std::string& input)
{
    std::cout << "===== input: \"" << input << "\" =====\n";
    ScalarConverter::convert(input);
    std::cout << std::endl;
}

static void runAllTests()
{
    runTest("'a'");
    runTest("'Z'");
    runTest("a");
    runTest("Z");

    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("2147483647");
    runTest("-2147483648");

    runTest("0.0f");
    runTest("-4.2f");
    runTest("3.14f");
    runTest("+inff");
    runTest("-inff");
    runTest("nanf");

    runTest("0.0");
    runTest("-4.2");
    runTest("3.14159");
    runTest("+inf");
    runTest("-inf");
    runTest("nan");

    runTest("abc");
    runTest("1.2.3");
    runTest("++1");
    runTest("''");
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage:\n";
        std::cout << "./convert <value>\n";
        std::cout << "./convert --test\n";
        return (0);
    }
    std::string arg = argv[1];
    if (arg == "--test")
    {
        runAllTests();
        return (0);
    }
    runTest(arg);
    return (1);
}