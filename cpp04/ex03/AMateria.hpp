/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:03:50 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/26 14:58:22 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include <iomanip>

class AMateria
{
    protected:
        std::string const & type;
    public:
        AMateria(std::string const & type);
        ~AMateria();
        AMateria& operator=(const AMateria &obj);
        AMateria(const AMateria &other);
        std::string const & getType() const; //Returns the materia type 
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
