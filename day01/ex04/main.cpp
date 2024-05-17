/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:11 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/13 14:08:00 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManip.hpp"

int main(int argc, char const *argv[])
{
	FileManip	file;

	if (argc != 4)
	{
		std::cout << "./notsed filename str1 str2" << std::endl;
		return 0;
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "problem opening " << argv[1] << std::endl;
		return 0;
	}
	if (!file.replace(argv[2], argv[3]))
	{
		std::cout << "problem creating " << argv[1] << ".replace" << std::endl; 
	}
	return 0;
}
