#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <vector>

class OccurrenceNotFoundException : public std::exception
{
    public:
        OccurrenceNotFoundException() {}
        const char* what() const throw()
        {
            return ("No occurrence was found in the container");
        }
};

template <typename T>
void easyfind(T& cont, int occurrence)
{
    try
    {
        for (typename T::iterator it = cont.begin(); it != cont.end(); ++it)
        {
            if (*it == occurrence)
            {
                std::cout << "Found it: " << *it << std::endl;
                return;
            }
        }
        throw OccurrenceNotFoundException();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

#endif