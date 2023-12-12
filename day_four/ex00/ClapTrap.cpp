/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:50:39 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/12 20:04:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"


ClapTrap::ClapTrap (void) : _name("Unnamed"), _HP(0), _EP(0), _AD(0) {

	std::cout << "CLAPTRAP default constructor called" << std::endl;
}
ClapTrap::ClapTrap (std::string name) : _name(name), _HP(10), _EP(10), _AD(0) {

	std::cout << "CLAPTRAP " <<  name << " constructor called " << std::endl;
}

ClapTrap::~ClapTrap () {

	std::cout << "CLAPTRAP " <<  this->_name << " destructor called " << std::endl;
}
ClapTrap::ClapTrap (const ClapTrap &c)  {

	*this = c;

	std::cout << "CLAPTRAP " <<  this->_name << " copy constructor called " << std::endl;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap &c) {

	std::cout << "CLAPTRAP " <<  this->_name << " copy assignator called " << std::endl;

	this->_name = c._name;
	this->_HP = c._HP;
	this->_EP = c._EP;
	this->_AD = c._AD;

	return (*this);
}

unsigned int	ClapTrap::getAD (void) const {

	return (this->_AD);
}

void	ClapTrap::stats (void) const {

	std::cout << this->_name << ": HP (" << this->_HP << ") EP (" << this->_EP;
	std::cout << ") AD (" << this->_AD << ")" << std::endl;
	return;
}

void	ClapTrap::attack (const std::string& target) {

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

void	ClapTrap::takeDamage (unsigned int amount) {

	if (this->_HP <= amount)
		this->_HP = 0;
	else
		this->_HP -= amount;
}

void	ClapTrap::beRepaired (int amount) {

	if (this->_EP == 0)
	{
		std::cout << "... " << this->_name << " tried to repairs himself"; 
		std::cout << " but nothing happened !" << std::endl;
		return ;
	}
	this->_HP += amount;
	std::cout << "UNTZ! " << this->_name << " has healed " << amount;
	std::cout << " amount, he's now at" << this->_HP << " !" << std::endl;
	this->_EP--;
	return ;
}
