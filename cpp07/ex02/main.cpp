#include "Array.hpp"

int main(void)
{
    Array<int>* emptyIntArray = new Array<int>();
    Array<int>* fullIntArray = new Array<int>(5);
    std::cout << "Empty array size: " << emptyIntArray->size() << std::endl;
    std::cout << "Full array size: " << fullIntArray->size() << std::endl;
    for (unsigned int i = 0; i < fullIntArray->size(); i++)
        (*fullIntArray)[i] = i * 10;
    for (unsigned int i = 0; i < fullIntArray->size(); i++)
        std::cout << "fullIntArray[" << i << "] = " << (*fullIntArray)[i] << std::endl;
    Array<int> copyArray(*fullIntArray);
    copyArray[0] = 999;
    std::cout << "Original [0] after copy modification: " << (*fullIntArray)[0] << std::endl;
    std::cout << "Copy [0]: " << copyArray[0] << std::endl;
    try
    {
        (*fullIntArray)[99] = 0;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: out of bounds access" << std::endl;
    }
    delete (emptyIntArray);
    delete (fullIntArray);
    return 0;
}