/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:50:39 by lcozdenm          #+#    #+#             */
/*   Updated: 2024/04/23 15:21:25 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"


ClapTrap::ClapTrap (void) : _name("Unnamed"), _HP(100), _EP(50), _AD(20) {

	std::cout << this->_classType << " default constructor called" << std::endl;
}
ClapTrap::ClapTrap (std::string name) : _name(name), _HP(100), _EP(50), _AD(20) {

	std::cout << this->_classType << " '" <<  name << "' constructor called " << std::endl;
}

ClapTrap::~ClapTrap () {

	std::cout << this->_classType << " '" <<  this->_name << "' destructor called " << std::endl;
}
ClapTrap::ClapTrap (const ClapTrap &c)  {

	std::cout << this->_classType << " '" <<  this->_name << "' copy constructor called " << std::endl;

	*this = c;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap &c) {

	std::cout << this->_classType << " '" <<  this->_name << "' copy assignator called into" << std::endl;

	this->_name = c._name;
	this->_HP = c._HP;
	this->_EP = c._EP;
	this->_AD = c._AD;

	return (*this);
}

unsigned int	ClapTrap::getAD (void) const {

	return (this->_AD);
}

bool	ClapTrap::energyLeft (void) const {

	return (this->_EP > 0);
}

bool	ClapTrap::healthLeft (void) const {

	return (this->_HP > 0);
}

void	ClapTrap::stats (void) const {

	std::cout << this->_name << ": HP (" << this->_HP << ") EP (" << this->_EP;
	std::cout << ") AD (" << this->_AD << ")" << std::endl;
	return;
}

void	ClapTrap::attack (const std::string& target) {

	if (this->_HP == 0)
	{
		std::cout << "... " << this->_name << " tried to attack"; 
		std::cout << " but they're out !" << std::endl;
		return ;
	}
	if (this->_EP == 0)
	{
		std::cout << "... " << this->_name << " tried to attack " << target;
		std::cout << " but nothing happened !" << std::endl;
		return ;
	}
	std::cout << "PLOP! " << this->_na me << " has done " << this->_AD;
	std::cout << " damage to " << target << " !" << std::endl;
	this->_EP--;
	return ;
}

void	ClapTrap::takeDamage (unsigned int amount) {

	if (this->_HP <= amount)
		this->_HP = 0;
	else
		this->_HP -= amount;
}

void	ClapTrap::beRepaired (int amount) {

	if (this->_HP == 0)
	{
		std::cout << "... " << this->_name << " tried to repairs themself"; 
		std::cout << " but they're out !" << std::endl;
		return ;
	}
	if (this->_EP == 0)
	{
		std::cout << "... " << this->_name << " tried to repairs themself"; 
		std::cout << " but nothing happened !" << std::endl;
		return ;
	}
	if (this->_HP + amount >= this->_HP)
		this->_HP += amount;
	else
		this->_HP =  std::numeric_limits<unsigned int>::max();
	std::cout << "UNTZ! " << this->_name << " has healed " << amount;
	std::cout << " amount, They're now at " << this->_HP << " !" << std::endl;
	this->_EP--;
	return ;
}

const std::string ClapTrap::_classType = "ClapTrap";