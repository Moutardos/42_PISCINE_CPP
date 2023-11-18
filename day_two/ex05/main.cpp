/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:11 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/11/18 13:11:33 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("");
	harl.complain("ERROR");
	harl.complain("error");

	return 0;
}
