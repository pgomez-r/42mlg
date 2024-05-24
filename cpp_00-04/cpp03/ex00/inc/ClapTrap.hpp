/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:05 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/24 12:40:45 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap{
	private:
		std::string	_name;
		unsigned int			_hitPts;
		unsigned int			_energyPts;
		unsigned int			_attackDmg;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &rhs);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		unsigned int		getHitPts(void);
		unsigned int		getEnergyPts(void);
		unsigned int		getAttackDmg(void);
};

#endif