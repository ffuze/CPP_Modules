#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN \"number sequence\"" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn;
        rpn.findSequenceResult(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}