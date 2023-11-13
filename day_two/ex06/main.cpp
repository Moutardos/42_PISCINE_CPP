/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:11 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/13 16:52:38 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	Harl	harl;

	if (argc != 2)
	{
		std::cout << "./HarlFilter LevelProblem";
		return 0;
	}
	harl.complain(argv[1]);
	return 0;
}
