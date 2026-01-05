/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:14:16 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::cout << "complain(\"DEBUG\"):" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "complain(\"INFO\"):" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "complain(\"WARNING\"):" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "complain(\"ERROR\"):" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "complain(\"debug\"):" << std::endl;
    harl.complain("debug");
    std::cout << std::endl;

    std::cout << "complain(\"INVALID\"):" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;

    std::cout << "complain(\"\"):" << std::endl;
    harl.complain("");
    std::cout << std::endl;

    std::cout << "complain(\"   \"):" << std::endl;
    harl.complain("");
    std::cout << std::endl;

    return 0;
}
