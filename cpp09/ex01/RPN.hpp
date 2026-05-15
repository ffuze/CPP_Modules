/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:41:26 by adegl-in          #+#    #+#             */
/*   Updated: 2026/05/15 14:41:01 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void findSequenceResult(std::string sequence);
};

#endif
