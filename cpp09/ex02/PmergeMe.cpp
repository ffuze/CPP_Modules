/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:53:39 by adegl-in          #+#    #+#             */
/*   Updated: 2026/05/15 17:52:23 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./PmergeMe.hpp"
# include <ctime>
# include <sys/time.h>
# include <algorithm>
# include <iomanip>
# include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _deque(other._deque), _vector(other._vector) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_deque = other._deque;
		_vector = other._vector;
	}
	return (*this);
}

// generate Jacobsthal's sequence until maxSize
// J(n) = J(n-1) + 2*J(n-2)
// example: J(2) = J(1) + 2*J(0)
// 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, ...
// J(0)=0
// J(1)=1
std::vector<int> generateJacobsthal(int maxSize)
{
	std::vector<int> jacobs;
	int j0 = 0;
    int j1 = 1;
	
	while (j1 <= maxSize)
	{
		jacobs.push_back(j1);
		int next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	return (jacobs);
}

void PmergeMe::mergeInsertSort_deque(std::deque<int>& arr)
{
	// check to see if stack has already one single element
	if (arr.size() <= 1)
		return;
	
	// 1) divide the stack in couples and order it by them
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> unpaired;
    
	for (size_t i = 0; i < arr.size(); i += 2)
	{
        // order the stack, having: a -> arr[i], b -> arr[i + 1]
		if (i + 1 < arr.size())
		{
			int a = arr[i];
			int b = arr[i + 1];
			if (a > b)
				std::swap(a, b);
			pairs.push_back(std::make_pair(a, b));
		}
        // check if there is a single number left out ( :'< )
		else
			unpaired.push_back(arr[i]);
	}
	
	// 2-a) get the larger number between each couple and order the results
	std::deque<int> larger;
	for (size_t i = 0; i < pairs.size(); i++)
		larger.push_back(pairs[i].second);
	
	// 2-b): call a recursive function to order (!!)
	mergeInsertSort_deque(larger);
	
    // 3) based on the larger numbers got for each couple, we can now
    // re-order the couples in the stack
	std::deque<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < larger.size(); i++) // 'larger' stuck numbers
	{
		for (size_t j = 0; j < pairs.size(); j++) // regular couples
		{
			if (pairs[j].second == larger[i])
			{
				sortedPairs.push_back(pairs[j]);
				pairs[j].second = -1; // Mark as used
				break;
			}
		}
	}
	
    // 3) BINARY SEARCH WITH JACOBNSAKDA (fuyck this shit ong frfr)
	std::vector<int> jacobs = generateJacobsthal(sortedPairs.size() - 1);
	
	std::deque<int> result;
	// add first the smaller number
	if (sortedPairs.size() > 0)
		result.push_back(sortedPairs[0].first);
    // add then the bigger number
	if (sortedPairs.size() > 0)
		result.push_back(sortedPairs[0].second);
	
    // trace which indexes were inserted
	std::deque<bool> inserted(sortedPairs.size(), false);
	inserted[0] = true;  // this means the first one was alreadty inserted
	
	// 3-a) insert the numbers following Jacobs' sequence
	for (size_t j = 0; j < jacobs.size(); j++)
	{
		int idx = jacobs[j];
		if (idx < (int)sortedPairs.size() && !inserted[idx])
		{
			// insert the smaller nmuber of the couple
			int nToInsert = sortedPairs[idx].first;
			std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			// insert the bigger number of the couple
			nToInsert = sortedPairs[idx].second;
			it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			inserted[idx] = true; // mark the numbers we just put as set (true) 
		}
	}
	
    // 4) put the reamining small numbers into the remaining empty spots (even non-Jacobs numbers)
    // same shit as before, except we are working into the couples stack
	for (size_t i = 1; i < sortedPairs.size(); i++)
	{
		if (!inserted[i])
		{
			int nToInsert = sortedPairs[i].first;
			std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			nToInsert = sortedPairs[i].second;
			it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			inserted[i] = true;
		}
	}
	// LIKE BEFORE, add even teh left out number(s)
	for (size_t i = 0; i < unpaired.size(); i++)
	{
		int nToInsert = unpaired[i];
		std::deque<int>::iterator it = std::lower_bound(result.begin(), result.end(), nToInsert);
		result.insert(it, nToInsert);
	}
	arr = result;
}

void PmergeMe::mergeInsertSort_vector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> unpaired;

	for (size_t i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 < arr.size())
		{
			int a = arr[i];
			int b = arr[i + 1];
			if (a > b)
				std::swap(a, b);
			pairs.push_back(std::make_pair(a, b));
		}
		else
			unpaired.push_back(arr[i]);
	}
	std::vector<int> larger;
	for (size_t i = 0; i < pairs.size(); i++)
    {
		larger.push_back(pairs[i].second);
    }

	mergeInsertSort_vector(larger);
    
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < larger.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == larger[i])
			{
				sortedPairs.push_back(pairs[j]);
				pairs[j].second = -1;
				break;
			}
		}
	}
    
	std::vector<int> result;
	// Genera la sequenza di Jacobsthal
	std::vector<int> jacobsthal = generateJacobsthal(sortedPairs.size() - 1);
	
	// Aggiungi il primo minore e il primo maggiore
	if (sortedPairs.size() > 0)
		result.push_back(sortedPairs[0].first);
	if (sortedPairs.size() > 0)
		result.push_back(sortedPairs[0].second);
	
	// Traccia quali indici sono stati inseriti
	std::vector<bool> inserted(sortedPairs.size(), false);
	inserted[0] = true;  // Il primo è già stato inserito
	
	// PASSO 1: Inserisci seguendo la sequenza di Jacobsthal
	for (size_t j = 0; j < jacobsthal.size(); j++)
	{
		int idx = jacobsthal[j];
		if (idx < (int)sortedPairs.size() && !inserted[idx])
		{
			// Inserisci il minore
			int nToInsert = sortedPairs[idx].first;
			std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			// Inserisci il maggiore
			nToInsert = sortedPairs[idx].second;
			it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			inserted[idx] = true;
		}
	}
	
	// PASSO 2: Inserisci i minori rimanenti negli spazi vuoti
	for (size_t i = 1; i < sortedPairs.size(); i++)
	{
		if (!inserted[i])
		{
			int nToInsert = sortedPairs[i].first;
			std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			nToInsert = sortedPairs[i].second;
			it = std::lower_bound(result.begin(), result.end(), nToInsert);
			result.insert(it, nToInsert);
			
			inserted[i] = true;
		}
	}

	for (size_t i = 0; i < unpaired.size(); i++)
	{
		int nToInsert = unpaired[i];
		std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), nToInsert);
		result.insert(it, nToInsert);
	}
	arr = result;
}

void PmergeMe::sort(int argc, char **argv)
{
    // PARSING CHECKKKK
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		
		// check if empty
		if (str.empty())
			throw (std::runtime_error("Empty string"));
		// check if negeative
		if (str[0] == '-')
			throw (std::runtime_error("Negative value"));
		// check if there are non-digit characters
		for (size_t j = 0; j < str.length(); j++)
		{
			if (!std::isdigit(str[j]))
				throw (std::runtime_error("Non-digit value found"));
		}
		long num = std::atol(str.c_str());
		if (num > INT_MAX)
			throw (std::runtime_error("overflowing value (INT_MAX)"));
		_deque.push_back(static_cast<int>(num));
		_vector.push_back(static_cast<int>(num));
	}
	if (_deque.empty())
		throw (std::runtime_error("Stack is empty XD"));
	
	// JUST INC ASE
	_dequeOriginal = _deque;
	_vectorOriginal = _vector;
	
	// get the us for the DEQUE
	struct timeval startDeque;
    struct timeval endDeque;
	gettimeofday(&startDeque, NULL);
	mergeInsertSort_deque(_deque);
	gettimeofday(&endDeque, NULL);
	_timeDeque = (endDeque.tv_sec - startDeque.tv_sec) * 1e6 + 
	             (endDeque.tv_usec - startDeque.tv_usec);
    
    // get the us for the VECTOR
	struct timeval startVector;
    struct timeval endVector;
	gettimeofday(&startVector, NULL);
	mergeInsertSort_vector(_vector);
	gettimeofday(&endVector, NULL);
	_timeVector = (endVector.tv_sec - startVector.tv_sec) * 1e6 + 
	              (endVector.tv_usec - startVector.tv_usec);
}

void PmergeMe::display()
{
	std::cout << "BEFORE: ";
	for (size_t i = 0; i < _dequeOriginal.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _dequeOriginal[i];
	}
	std::cout << std::endl;
	
	std::cout << "AFTER: ";
	for (size_t i = 0; i < _deque.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << _deque[i];
	}
	std::cout << std::endl;

    // DEQUE
	std::cout << "Time to process a range of " << _deque.size() 
		<< " elements with std::deque : " << std::fixed << std::setprecision(5) 
		<< _timeDeque << " us" << std::endl;
	
	// VECTOR
	std::cout << "Time to process a range of " << _vector.size() 
		<< " elements with std::vector : " << std::fixed << std::setprecision(5) 
		<< _timeVector << " us" << std::endl;
}