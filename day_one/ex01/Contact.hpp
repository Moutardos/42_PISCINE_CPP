/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:03 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/16 17:29:55 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT

# include <iostream>

class Contact {

public:
	Contact		(void);
	~Contact	(void);

	std::string	getFname		(void) const;
	std::string	getLname		(void) const;
	std::string	getNname		(void) const;
	std::string	getNumber		(void) const;
	std::string	getSecret		(void) const;
	bool		setLname		(std::string lname);
	bool		setFname		(std::string fname);
	bool		setNname		(std::string nname);
	bool		setNumber		(std::string number);
	bool		setSecret		(std::string secret);
	static bool	checkNumber		(std::string number);
	static bool	checkName		(std::string name);

	bool		initialize		(std::string fname, std::string lname, 
								std::string nname, std::string number, std::string secret);
	void		copy			(Contact &contact);
	void		resetContact	(void);
	void		displayInfo		(void) const;

private:
	std::string	_fname;
	std::string	_lname;
	std::string	_nname;
	std::string	_number;
	std::string	_secret;

};

#endif