#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	Zombie	*zombies = new Zombie[N];

	if (N < 1)
		return (0);
	if (zombies == NULL)
		return (0);
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}