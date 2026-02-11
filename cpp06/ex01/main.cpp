#include "Serializer.hpp"

int main()
{
    playerData.nickname = "alek#R1M";
    playerData.hoursPlayed = 1000;
    playerData.rank = 'P';

    std::cout << "Original Data:\n" << playerData << std::endl;
    std::cout << "Address: " << &playerData << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serialization::serialize(&playerData);
    std::cout << "Serialized to uintptr_t: " << serialized << std::endl;
    std::cout << std::endl;

    Data* deserialized = Serialization::deserialize(serialized);
    std::cout << "Deserialized Data:\n" << *deserialized << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << std::endl;
    if (&playerData == deserialized)
        std::cout << "Pointers are matching" << std::endl;
    else
        std::cout << "Pointers are NOT matching" << std::endl;

    return 0;
}