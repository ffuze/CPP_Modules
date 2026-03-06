#include "Span.hpp"

void test_span_creation()
{
    Span sp(5);
    if (sp.getSize() != 5)
        throw std::runtime_error("test_span_creation FAILED");
    std::cout << "test_span_creation passed" << std::endl;
}

void test_span_add_numbers()
{
    Span sp(3);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    if (sp.getSize() != 3)
        throw std::runtime_error("test_span_add_numbers FAILED");
    std::cout << "test_span_add_numbers passed" << std::endl;
}

void test_span_overflow()
{
    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    try {
        sp.addNumber(3);
        throw std::runtime_error("test_span_overflow FAILED: exception not thrown");
    } catch (const std::exception& e) {
        std::cout << "test_span_overflow passed" << std::endl;
    }
}

void test_span_shortest_span()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    if (sp.shortestSpan() != 2)
    {
        std::cout << "shortest span found: " << sp.shortestSpan() << std::endl;
        throw std::runtime_error("test_span_shortest_span FAILED");
    }
    std::cout << "test_span_shortest_span passed" << std::endl;
}

void test_span_longest_span()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    if (sp.longestSpan() != 14)
        throw std::runtime_error("test_span_longest_span FAILED");
    std::cout << "test_span_longest_span passed" << std::endl;
}

void test_span_not_enough_numbers()
{
    Span sp(5);
    sp.addNumber(5);
    try {
        sp.shortestSpan();
        throw std::runtime_error("test_span_not_enough_numbers FAILED: exception not thrown");
    } catch (const std::exception& e) {
        std::cout << "test_span_not_enough_numbers passed" << std::endl;
    }
}

int main()
{
    try {
        test_span_creation();
        test_span_add_numbers();
        test_span_overflow();
        test_span_shortest_span();
        test_span_longest_span();
        test_span_not_enough_numbers();
        std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}