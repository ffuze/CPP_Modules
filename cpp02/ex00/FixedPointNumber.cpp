#include "FixedPointNumber.hpp"

FixedPointNumber::FixedPointNumber()
{
    this->_raw = 0;
    std::cout << "Default constructot called" << std::endl;
}

FixedPointNumber::~FixedPointNumber()
{
    std::cout << "Destructor called" << std::endl;
}

FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _raw = obj.getRawBits();
    return (*this);
}

FixedPointNumber::FixedPointNumber(const FixedPointNumber &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(obj);
}

int FixedPointNumber::getRawBits(void) const
{
    return (std::cout << "getRawBits member function called" << std::endl, FixedPointNumber::_raw);
}

void FixedPointNumber::setRawBits(int const raw)
{
    this->_raw = raw;
}