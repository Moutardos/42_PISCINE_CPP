#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	Animal *fab = new Animal();
	Animal *paf = new Dog();
	Animal	*gab = new Cat();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Hi, i'm gab and I'm " << gab->getType() << std::endl;
	gab->makeSound();
	std::cout << "Hi, i'm fab and I'm " << fab->getType() << std::endl;
	fab->makeSound();
	std::cout << "Hi, i'm paf and I'm " << paf->getType() << std::endl;
	paf->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;

	delete fab;
	delete gab;
	delete paf;

	std::cout << std::endl;
	std::cout << std::endl;

	WrongAnimal *baf = new WrongAnimal();
	WrongAnimal	*bag = new WrongCat();

	std::cout << "Hi, i'm baf and I'm " << baf->getType() << std::endl;
	baf->makeSound();
	std::cout << "Hi, i'm fab and I'm " << bag->getType() << std::endl;
	bag->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;

	delete bag;
	delete baf;

	return 0;
}
