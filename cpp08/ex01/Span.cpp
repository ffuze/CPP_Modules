#include "Span.hpp"

Span::Span(unsigned int N)
{
    std::vector<int> container(N);
}

Span::VectorOutOfBoundsException::VectorOutOfBoundsException() {}

Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
}

Span::Span(const Span& copy)
{
    this->operator=(copy);
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        this->spans = obj.spans;
        this->spanSize = obj.spanSize;
    }
    return (*this);
}

void Span::addNumber(const int value)
{
    if (this->spans.size() > this->spanSize)
        throw (VectorOutOfBoundsException());
    this->spans.push_back(value);
}

int Span::shortestSpan() const
{
    typename T::
}

