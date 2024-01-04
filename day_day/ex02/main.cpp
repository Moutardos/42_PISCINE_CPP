#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
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
	// std::cout << "Hi, i'm fab and I'm " << fab->getType() << std::endl;
	// fab->makeSound();
	std::cout << "Hi, i'm paf and I'm " << paf->getType() << std::endl;
	paf->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	
	// delete fab;
	delete gab;
	delete paf;
	
	std::cout << std::endl;
	std::cout << std::endl;

	// WrongAnimal *baf = new WrongAnimal();
	// WrongAnimal	*bag = new WrongCat();

	// std::cout << "Hi, i'm baf and I'm " << baf->getType() << std::endl;
	// baf->makeSound();
	// std::cout << "Hi, i'm fab and I'm " << bag->getType() << std::endl;
	// bag->makeSound();

	// std::cout << std::endl;
	// std::cout << std::endl;

	// delete bag;
	// delete baf;

	Brain	*brain = new Brain();
	brain->displayIdeas();

	delete brain;

	Animal	*array[100];

	for (int i = 0; i < 50; ++i)
		array[i] = new Dog();
	for (int i = 50; i < 100; ++i)
		array[i] = new Cat();

	for (int i = 0; i < 100; ++i)
		delete array[i];


    {
        Cat    cat;
        Cat    catcopy;
	
	    cat.setIdea(0, "coucou");
        cat.setIdea(20, "salut");
        cat.setIdea(45, "heyyy");
        catcopy = cat;
        Cat    catcopy2(cat);
		Cat		*gab = new Cat(cat);
		cat.setIdea(1, "cat original idea");
		catcopy2.setIdea(83, "should be alone");

		std::cout << "CAT ORIGINAL" << std::endl;
		cat.displayBrain();

		std::cout << "CAT COPY ASSIGNATOR" << std::endl;
		catcopy.displayBrain();

		std::cout << "CAT COPY CONSTRUCTOR" << std::endl;

		catcopy2.displayBrain();

		std::cout << "CAT* COPY CONSTRUCTOR" << std::endl;

		gab->displayBrain();

		delete gab;
    }

	return 0;
}
