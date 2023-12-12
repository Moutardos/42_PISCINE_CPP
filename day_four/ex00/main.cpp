/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:44:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/12 20:00:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap benoit;
	ClapTrap mathilde = ClapTrap("Mathilde");
	benoit = ClapTrap("Benoit");

	std::cout << std::endl;

	benoit.attack("Mathilde");
	mathilde.takeDamage(benoit.getAD());
	mathilde.stats();
	benoit.stats();
	std::cout << std::endl;
	return 0;
}
