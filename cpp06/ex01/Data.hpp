#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <fstream>

struct Data
{
    std::string nickname;
    char rank;
    int hoursPlayed;
};

extern Data playerData;

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif