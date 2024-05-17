#include "Zombie.hpp"

int main(void)
{
	Zombie *horde =  zombieHorde(15, "ouais");

	if (horde == NULL)
		return 1;
	for (int i = 0; i < 15; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}
