/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/30 23:23:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	benoit("Benoit");
	ClapTrap	mathilde = ClapTrap("Mathilde");

	std::cout << std::endl;

	mathilde.stats();
	benoit.stats();
	benoit.attack("Mathilde");
	mathilde.takeDamage(benoit.getAD());
	mathilde.stats();
	benoit.stats();

	std::cout << std::endl;

	benoit.beRepaired(1);
	while (benoit.energyLeft())
		benoit.attack("the wall");
	benoit.beRepaired(1);
	benoit.stats();
	
	std::cout << std::endl;

	ClapTrap	benoitCopy = benoit;
	benoitCopy.attack("Mathilde");

	std::cout << std::endl;
	return 0;
}
