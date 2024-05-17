/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/30 23:28:40 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	benoit("Benoit");
	ScavTrap	mathilde = ScavTrap("Mathilde");

	// ClapTrap	fakeA = ScavTrap();
	// ScavTrap	fakeB;
	// fakeB = fakeA;

	std::cout << std::endl;

	mathilde.stats();
	benoit.stats();
	mathilde.attack("Benoit");
	benoit.takeDamage(mathilde.getAD());
	mathilde.stats();
	benoit.stats();

	std::cout << std::endl;
	
	while (benoit.healthLeft() && mathilde.energyLeft())
	{
		mathilde.attack("Benoit");
		benoit.takeDamage(mathilde.getAD());
	}
	
	std::cout << std::endl;

	mathilde.stats();
	benoit.stats();
	
	std::cout << std::endl;

	mathilde.guardGate();
	mathilde.guardGate();

	std::cout << std::endl;

	return 0;
}
