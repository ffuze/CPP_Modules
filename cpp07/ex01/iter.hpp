#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>
# include <string>

template <typename T1, typename T2>
void iter(T1 *address, const int length, T2 f)
{
    for (int i = 0; i < length; i++)
        f(address[i]);
}

#endif