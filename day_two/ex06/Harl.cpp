/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:26:23 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/13 16:52:49 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl (void) {

	this->_fun[3] = &Harl::debug;
	this->_fun[2] = &Harl::info;
	this->_fun[1] = &Harl::warning;
	this->_fun[0] = &Harl::error;
	this->_index[0] = "DEBUG";
	this->_index[1] = "INFO";
	this->_index[2] = "WARNING";
	this->_index[3] = "ERROR";

}

Harl::~Harl (void) {}

void	Harl::debug (void) {

	std::cout << "eh ca debug par ici" << std::endl;
}

void	Harl::info (void) {

	std::cout << "eh ca donnes des infos par ici" << std::endl;
}

void	Harl::warning	(void) {

	std::cout << "eh ca warning par ici" << std::endl;
}

void	Harl::error (void) {

	std::cout << "eh error ici" << std::endl;
}

void	Harl::complain	(std::string level) {

	int	index_level = -1;

	if (level.empty())
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_index[i].compare(level))
		{
			index_level = i;
			break;
		}
	}
	switch (index_level) {
		case 0:
			(this->*(this->_fun[0]))();
		case 1:
			(this->*(this->_fun[1]))();
		case 2:
			(this->*(this->_fun[2]))();
		case 3:
			(this->*(this->_fun[3]))();
		case -1:
			std::cout << "mouais.. pas sur" << std::endl;

	}
}