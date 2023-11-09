/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:09:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/09 15:35:56 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string string2 = "no";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory adress of string" << std::setw(6)<< ": " << &string << std::endl;
	std::cout << "Memory adress of stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory adress of stringREF : " << &stringREF << std::endl;

	std::cout << "Value of string" << std::setw(14)<< ": "  << string << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF : " << stringREF << std::endl;
	
	return 0;
}

