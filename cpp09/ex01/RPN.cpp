#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

void RPN::findSequenceResult(std::string sequence)
{
    // "8 9 * 9 - 9 - 9 - 4 - 1 +"
    
    this->_stack.push();
}
