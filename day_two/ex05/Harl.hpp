#ifndef HARL_H
# define HARL_H

# include <iostream>

class Harl {

public :
	Harl	(void);
	~Harl	(void);

	void	complain	(std::string level);

private :
	void 		(Harl::*_fun[4])(void);
	std::string	_index[4];

	void	debug	(void);
	void	info	(void);
	void	warning	(void);
	void	error	(void);
};



#endif