#include "PmergeMe.hpp"
# include <list>

# define ListPair std::list<CPair<Type> *>


template <typename Type>
ListPair	MainFunctionList(ListPair current)
{
	typename ListPair::iterator	it;

	it = current.begin();

}




int main(void)
{
	int	a = 9;
	int	b = 7;
	int	c = 8;
	int	d = 1123;

	CPair<int>	nodeA(a);
	CPair<int>	nodeC(c);
	CPair<int>	nodeB(b);
	CPair<int>	nodeD(d);
	CPair<int>	nodeAB(&nodeA, &nodeB);
	CPair<int>	nodeE_(&nodeA, &nodeB);
	CPair<int>	nodeCD(&nodeC, &nodeD);
	CPair<int>	base(&nodeAB, &nodeCD);

	std::cout << "[9,7,8,1123]" << std::endl;
	std::cout << "->\n";
	std::cout << "[";
	CPair<int>::displayPair(nodeAB);
	std::cout << ", ";
	CPair<int>::displayPair(nodeCD);
	std::cout << "]\n";
	nodeAB.sort();
	nodeCD.sort();
	std::cout << "->\n";
	std::cout << "[";
	CPair<int>::displayPair(nodeAB);
	std::cout << ", ";
	CPair<int>::displayPair(nodeCD);
	std::cout << "]\n";

	std::cout << "->\n";
	std::cout << "[";
	CPair<int>::displayPair(base);
	std::cout << "]\n";
	base.sort();
	std::cout << "->\n";
	std::cout << "[";
	CPair<int>::displayPair(base);
	std::cout << "]\n";

	return 0;
}
