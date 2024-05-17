/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:50:39 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/12/16 21:02:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"


FragTrap::FragTrap (void) : ClapTrap() {

	std::cout << this->_classType << " default constructor called" << std::endl;
}

FragTrap::FragTrap (std::string name) {

	this->_name = name;
	this->_HP = 100;
	this->_EP = 100;
	this->_AD = 30;

	std::cout << this->_classType << " '" <<  name << "' constructor called " << std::endl;
}

FragTrap::~FragTrap () {

	std::cout << this->_classType << " '" <<  this->_name << "' destructor called " << std::endl;
}

FragTrap::FragTrap (const FragTrap &c)  {

	std::cout << this->_classType << " '" <<  this->_name << "' copy constructor called " << std::endl;

	*this = c;
}

FragTrap	&FragTrap::operator= (const FragTrap &c) {

	std::cout << this->_classType << " '" <<  this->_name << "' copy assignator called into" << std::endl;

	this->_name = c._name;
	this->_HP = c._HP;
	this->_EP = c._EP;
	this->_AD = c._AD;

	return (*this);
}

void	FragTrap::highFivesGuys	(void) {
	if (this->_HP == 0)
		std::cout << "... " << this->_name << " is dead!" << std::endl;
	else	
		std::cout << this->_name << " is lifting his hand for a high-five!" << std::endl;

}

const std::string FragTrap::_classType = "FragTrap";