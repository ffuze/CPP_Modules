#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->spanSize = N;
	this->spans = std::vector<int>();
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

static int getBiggest(std::vector<int> spans)
{
	if (spans.empty())
		return (0);
	return (*std::max_element(spans.begin(), spans.end()));
}

// find the smallest differeece between two numbers inm the vector
int Span::shortestSpan() const
{
	int min = getBiggest(spans);
	int diff = 0;
	try
	{
		for (unsigned int i = 0; i < this->spanSize; i++)
		{
			std::cout << "(short) spans: " << spans[i] << std::endl;
			if (this->spans[i + 1])
			{
				std::cout << "(short) spans + 1: " << spans[i + 1] << std::endl;
				diff = this->spans[i] - this->spans[i + 1];
				std::cout << "(short) diff : " << diff << std::endl;
				if (diff < min)
				{
					if (diff < 0)
						diff = abs(diff);
					min = diff;
				}
				std::cout << "(short) min: " << min << std::endl;
			}
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (min);
}

// find the smallest differeece between two numbers inm the vector
int Span::longestSpan() const
{
	int max = 0;
	int diff = 0;
	try
	{
		for (unsigned int i = 0; i < this->spanSize; i++)
		{
			std::cout << "(long) spans: " << spans[i] << std::endl;
			if (this->spans[i + 1])
			{
				std::cout << "(long) spans + 1: " << spans[i + 1] << std::endl;
				diff = this->spans[i] - this->spans[i + 1];
				std::cout << "(long) diff : " << diff << std::endl;
				if (diff < 0)
					diff = abs(diff);
				if (diff > max)
					max = diff;
				std::cout << "(long) maxc : " << max << std::endl;
			}
		}	
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (max);
}
