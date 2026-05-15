/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:54:06 by adegl-in          #+#    #+#             */
/*   Updated: 2026/05/15 15:35:07 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <string>
# include <cstdlib>

class PmergeMe
{
	private:
		std::deque<int> _deque;
		std::deque<int> _dequeOriginal;
		std::vector<int> _vector;
		std::vector<int> _vectorOriginal;
		double _timeDeque;
		double _timeVector;
		void mergeInsertSort_deque(std::deque<int>& arr);
		void mergeInsertSort_vector(std::vector<int>& arr);
		
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void sort(int argc, char **argv);
		void display();
};

#endif