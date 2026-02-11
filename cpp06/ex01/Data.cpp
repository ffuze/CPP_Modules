#include "Data.hpp"

Data playerData;

std::ostream& operator<<(std::ostream& os, const Data& data)
{
    os << "Nick: " << data.nickname << "\nRank: " << data.rank << "\nTotal Hours: " << data.hoursPlayed << '\n';
    return (os);
}
