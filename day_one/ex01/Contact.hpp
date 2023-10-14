/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:03 by lcozdenm          #+#    #+#             */
/*   Updated: 2023/10/14 20:11:08 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
# define CONTACT

# include <iostream>

class Contact {

public:
	Contact		(std::string fname, std::string lname, 
				std::string nname, std::string number, std::string secret);
	Contact		(void);
	~Contact	(void);
	std::string	getFname     (void) const;
	std::string	getLname     (void) const;
	std::string	getNname     (void) const;
	std::string	getNumber    (void) const;
	std::string	getSecret    (void) const;
	void		setLname     (std::string lname);
	void		setFname     (std::string fname);
	void		setNname     (std::string nname);
	void		setNumber    (std::string number);
	void		setSecret    (std::string secret);
	void		resetContact (void);
	void		displayInfo  (void) const;
	static bool	checkNumber  (std::string new_number);

private:
	std::string const _fname;
	std::string const _lname;
	std::string const _nname;
	std::string _number;
	std::string const _secret;

};

#endif