/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:41:11 by adegl-in          #+#    #+#             */
/*   Updated: 2026/05/15 14:49:31 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::string token;
	std::stringstream ss(sequence);
	
	while (std::getline(ss, token, ' '))
	{
		// avoid empty tokens
		if (token.empty())
			continue;
		// check if is a valid number, either positive or negative
		if (std::isdigit(token[0]) || (token[0] == '-' && token.length() > 1))
			_stack.push(atoi(token.c_str()));
		// check if the used operator is valid
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			// check is there are at least two numbers into the stack
			if (_stack.size() < 2)
				throw (std::runtime_error("ERROR: minimum two numbers required to proceed"));
			// get the first two numbers to operate on
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			// OPERATIONS
			int result = 0;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw (std::runtime_error("ERROR: divison by 0 found"));
				result = a / b;
			}
			// put the result on the stack
			_stack.push(result);
		}
		else
			throw (std::runtime_error("ERROR: invalid token"));
	}
	// 
	if (_stack.size() != 1)
		throw (std::runtime_error("Error: invalid expression"));
	std::cout << _stack.top() << std::endl;
}
