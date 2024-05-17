#ifndef FragTrap_H
# define FragTrap_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap	(void);
	FragTrap	(const FragTrap &c);
	FragTrap	(std::string name);
	~FragTrap	(void);
	FragTrap	&operator=	(const FragTrap &c);
	
	void			highFivesGuys	(void);

protected:
	static const std::string	_classType;

};

#endif