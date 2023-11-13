/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:38:45 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/09 19:11:14 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name) :  _weapon(nullptr), _name(name) {}

HumanB::~HumanB (void) {}

void	HumanB::attack (void) {

	
	if (this->_weapon == nullptr)
		std::cout << this->_name << " tries to attack.. but has no weapon!" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon (Weapon &weapon) {

	this->_weapon = &weapon;
}
