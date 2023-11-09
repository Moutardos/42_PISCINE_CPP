#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	Zombie zombie = Zombie("hector2");

	Zombie *horde =  zombieHorde(100, "ouais");
	horde->announce();
	delete [] horde;
	return 0;
}
