#ifndef ZOMBIE
# define ZOMBIE

# include <iostream>

class Zombie {

public:
	Zombie	(std::string name);
	Zombie	(void);
	~Zombie	(void);

	void	setName		(std::string name);
	void	announce 	(void);

private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif