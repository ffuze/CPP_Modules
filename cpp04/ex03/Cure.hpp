/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:34:08 by adegl-in          #+#    #+#             */
/*   Updated: 2026/01/26 14:58:22 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	Cure(std::string const & type);
	~Cure();
	Cure& operator=(const Cure &obj);
	Cure(const Cure &other);
	virtual Cure* clone() const;
};

#endif
