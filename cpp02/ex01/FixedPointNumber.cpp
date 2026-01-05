#include "FixedPointNumber.hpp"

FixedPointNumber::FixedPointNumber()
{
    this->_raw = 0;
    std::cout << "Default constructor called" << std::endl;
}

FixedPointNumber::FixedPointNumber(const int value)
{
    _raw = value * 256;
    std::cout << "Int constructor called" << std::endl;
}

FixedPointNumber::FixedPointNumber(const float value)
{
    _raw = roundf(value * 256.0f);
    std::cout << "Float constructor called" << std::endl;
}

FixedPointNumber::FixedPointNumber(const FixedPointNumber &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(obj);
}

FixedPointNumber::~FixedPointNumber()
{
    std::cout << "Destructor called" << std::endl;
}

int FixedPointNumber::toInt() const
{
    return (_raw / 256);
}

float FixedPointNumber::toFloat() const
{
     return ((float)_raw / 256.0f);
}

FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _raw = obj.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const FixedPointNumber &obj)
{
    os << obj.toFloat();
    return (os);
}

int FixedPointNumber::getRawBits(void) const
{
    return (FixedPointNumber::_raw);
}

void FixedPointNumber::setRawBits(int const raw)
{
    this->_raw = raw;
}