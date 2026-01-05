/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:10:25 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/03 12:14:16 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void mega_capitalizer(int argc, char *argv[])
{
	std::string sentence;
	
	sentence = "\0";
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (islower(argv[i][j]))
				sentence += toupper(argv[i][j]);
			else if (argv[i][j] != '"')
				sentence += argv[i][j];
			else if (argv[i][j] == ' ')
				sentence += " ";
		}
	}
	std::cout << sentence << std::endl;
}

static void very_loud_noise(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 1)
		return (0);
	else if (argc < 2)
		very_loud_noise();
	else
		mega_capitalizer(argc, argv);
	return (0);
}
