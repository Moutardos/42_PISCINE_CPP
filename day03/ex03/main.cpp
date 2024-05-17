/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/30 23:31:31 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	benoit("Benoit");
	ScavTrap	mathilde = ScavTrap("Mathilde");
	FragTrap	leon = FragTrap("Leon");

	// ClapTrap	fakeA = ScavTrap("Fake");
	// ScavTrap	fakeB = FragTrap("non");
	// fakeB = fakeA;

	mathilde.stats();
	leon.stats();

	std::cout << std::endl;
	
	leon.highFivesGuys();

	while ((mathilde.healthLeft() && leon.healthLeft()) && (mathilde.energyLeft() || leon.energyLeft()))
	{
		mathilde.attack("Leon");
		leon.takeDamage(mathilde.getAD());
		if (leon.healthLeft())
		{
			leon.attack("Mathilde");
			mathilde.takeDamage(leon.getAD());
		}
		if (mathilde.healthLeft())
			mathilde.beRepaired(7);
	}
	
	std::cout << std::endl;

	mathilde.stats();
	leon.stats();
	
	mathilde.beRepaired(100000);
	leon.beRepaired(100000);

	mathilde.stats();
	leon.stats();

	std::cout << std::endl;
	std::cout << std::endl;

	mathilde.guardGate();
	mathilde.guardGate();

	std::cout << std::endl;

	return 0;
}
#include "DiamondTrap.hpp"
