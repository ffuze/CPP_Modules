/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:07:37 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/19 15:22:53 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        void makeSound() const;
        std::string getType() const;
        void setType(std::string type);
};

#endif
