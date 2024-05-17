/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:50:39 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/16 21:00:56 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"


ScavTrap::ScavTrap (void) : ClapTrap() {

	std::cout << this->_classType << " default constructor called" << std::endl;

	this->_gateKeep = false;
}
ScavTrap::ScavTrap (std::string name) : ClapTrap(name) {

	std::cout << this->_classType << " '" <<  name << "' constructor called " << std::endl;

	this->_gateKeep = false;
}

ScavTrap::~ScavTrap () {

	std::cout << this->_classType << " '" <<  this->_name << "' destructor called " << std::endl;
}
ScavTrap::ScavTrap (const ScavTrap &c)  {

	std::cout << this->_classType << " '" <<  this->_name << "' copy constructor called " << std::endl;

	*this = c;
}

ScavTrap	&ScavTrap::operator= (const ScavTrap &c) {

	std::cout << this->_classType << " '" <<  this->_name << "' copy assignator called into" << std::endl;

	this->_name = c._name;
	this->_HP = c._HP;
	this->_EP = c._EP;
	this->_AD = c._AD;
	this->_gateKeep = c._gateKeep;

	return (*this);
}

void	ScavTrap::attack (const std::string& target) {

	std::cout << this->_classType << ": ";
	if (this->_EP == 0)
	{
		std::cout << "... " << this->_name << " tried to attack " << target;
		std::cout << " but nothing happened !" << std::endl;
		return ;
	}
	std::cout << "PLOP! " << this->_name << " has done " << this->_AD;
	std::cout << " damage to " << target << " !" << std::endl;
	this->_EP--;
	return ;
}

void ScavTrap::guardGate (void) {

	if (this->_HP == 0)
		std::cout << "... " << this->_name << " is dead!" << std::endl;
	else if (!this->_gateKeep)
	{
		std::cout << "DING! " << this->_name << " is now gatekeeping" << std::endl;
		this->_gateKeep = true;
	}
	else
		std::cout << "... " << this->_name << " is already gatekeeping!" << std::endl;


}
const std::string ScavTrap::_classType = "ScavTrap";