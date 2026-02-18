#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>
# include <string>

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T myMin(T a, T b)
{
    return ((a < b) ? a : b);
}

template <typename T>
T myMax(T a, T b)
{
    return ((a > b) ? a : b);
}

#endif