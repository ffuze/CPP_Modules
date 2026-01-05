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

Harl::Harl()
{
}

Harl::~Harl()
{
}

static int  getIntLevel(std::string level)
{
    if (level == "DEBUG")
        return (0);
    if (level == "INFO")
        return (1);
    if (level == "WARNING")
        return (2);
    if (level == "ERROR")
        return (3);
    return (-1);
}

void Harl::complain(std::string level)
{
    void (Harl::*actions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    switch (getIntLevel(level))
    {
        case 0:
            (this->*actions[0])();
            break;
        case 1:
            (this->*actions[1])();
            break;
        case 2:
            (this->*actions[2])();
            break;
        case 3:
            (this->*actions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
