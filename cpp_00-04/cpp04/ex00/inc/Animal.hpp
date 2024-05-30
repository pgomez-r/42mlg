/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:06 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 16:15:31 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO - virtual destructor? virtual ~Animal();
// TODO - const methods? void makeSound(void) const;

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal(void);

		Animal &operator=(const Animal &rhs);
		
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif