/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:38:39 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/09 18:53:11 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon	(std::string type) : _type(type) {}
Weapon::~Weapon	(void) {}

void	Weapon::setType (std::string type) {

	this->_type = type;
	return;
}

std::string	Weapon::getType (void) {

	return (this->_type);
}

