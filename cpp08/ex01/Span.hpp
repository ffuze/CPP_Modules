#ifndef SPAN_HPP
# define SPAN_HPP

# include <bits/stdc++.h>

class Span
{
    private:
        std::vector<int> spans;
        unsigned int spanSize;
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span& copy);
        Span& operator=(const Span& obj);
        void addNumber(const int value);
        int shortestSpan() const;
        int longestSpan() const;
        class VectorOutOfBoundsException : public std::exception
        {
            public:
                VectorOutOfBoundsException();
                const char* what() const throw()
                {
                    return ("Cannot add more numbers into the vector");
                }
        };
        unsigned int getSize() const
        {
            return (spanSize);
        }
};

#endif