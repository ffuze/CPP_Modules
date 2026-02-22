#include "Serializer.hpp"

int main()
{
    playerData.nickname = "alek#R1M";
    playerData.hoursPlayed = 1500;
    playerData.rank = 'P';

    std::cout << "Original data:\n" << playerData;
    std::cout << "Struct address: " << &playerData << std::endl;

    uintptr_t serialized = Serialization::serialize(&playerData);
    std::cout << "\nSerialized address: " << serialized << std::endl;
    std::cout << std::endl;

    Data* deserialized = Serialization::deserialize(serialized);
    std::cout << "Deserialized data:\n" << *deserialized;
    std::cout << "Address got from serialized data: " << deserialized << std::endl;
    std::cout << std::endl;
    if (&playerData == deserialized)
        std::cout << "Pointers (addresses) are the same !" << std::endl;
    else
        std::cout << "Pointers (addresses) are not matching (wtf how)" << std::endl;

    return 0;
}