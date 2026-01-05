/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:14:16 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "DEBUG: some random words cuz im retarded n idk what to say" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: some random words cuz im retarded n idk what to say" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: some random words cuz im retarded n idk what to say" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR: some random words cuz im retarded n idk what to say" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*actions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*actions[i])();
        }
    }
}
