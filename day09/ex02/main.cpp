#include "PmergeMe.hpp"
# include <list>





int main(void)
{
	int	a = 30;
	int	b = 10;
	int	c = 20;
	int	d = 50;
	int e = 40;
	int f = 1;
	int g = 89;
	int h = 7;

	CPair<int>	nodeA(a);
	CPair<int>	nodeC(c);
	CPair<int>	nodeB(b);
	CPair<int>	nodeD(d);
	CPair<int>	nodeE(e);
	CPair<int>	nodeF(f);
	CPair<int>	nodeG(g);
	CPair<int>	nodeH(h);
	CPair<int>	nodeAB(&nodeA, &nodeB);
	CPair<int>	nodeEF(&nodeE, &nodeF);
	CPair<int>	nodeCD(&nodeC, &nodeD);
	CPair<int>	nodeGH(&nodeG, &nodeH);
	CPair<int>	nodeABCD(&nodeAB, &nodeCD);
	CPair<int>	nodeEFGH(&nodeEF, &nodeGH);
	CPair<int>	base(&nodeABCD, &nodeEFGH);

	// std::cout << "[30, 10, 20, 50, 40, 1, 89, 7]" << std::endl;
	// std::cout << "\n\n";
	// std::cout << "[";
	// CPair<int>::displayPair(nodeAB);
	// std::cout << ", ";
	// CPair<int>::displayPair(nodeCD);
	// std::cout << ",";
	// CPair<int>::displayPair(nodeEF);
	// std::cout << ",";
	// CPair<int>::displayPair(nodeGH);
	// std::cout << "]\n";
	// std::cout << "->\n";
	// nodeAB.sort();
	// nodeCD.sort();
	// nodeEF.sort();
	// nodeGH.sort();
	// std::cout << "[";
	// CPair<int>::displayPair(nodeAB);
	// std::cout << ", ";
	// CPair<int>::displayPair(nodeCD);
	// std::cout << ",";
	// CPair<int>::displayPair(nodeEF);
	// std::cout << ",";
	// CPair<int>::displayPair(nodeGH);
	// std::cout << "]\n\n";

	// std::cout << "->\n";
	// std::cout << "[";
	// CPair<int>::displayPair(nodeABCD);
	// std::cout << ",";
	// CPair<int>::displayPair(nodeEFGH);
	// std::cout << "]\n";
	// nodeABCD.sort();
	// nodeEFGH.sort();
	// std::cout << "->\n";
	// std::cout << "[";
	// CPair<int>::displayPair(nodeABCD);
	// std::cout << ",";
	// CPair<int>::displayPair(nodeEFGH);
	// std::cout << "]\n";
	// std::cout << "\n";
	// std::cout << "[";
	// CPair<int>::displayPair(base);
	// std::cout << "]\n";
	// base.sort();
	// std::cout << "->\n";
	// std::cout << "[";
	// CPair<int>::displayPair(base);
	// std::cout << "]\n";

	std::list<CPair<int>* > test;

	

	test.push_back(&nodeA);
	test.push_back(&nodeB);
		test.push_back(&nodeC);
			test.push_back(&nodeD);
				test.push_back(&nodeE);
					test.push_back(&nodeF);
						test.push_back(&nodeG);
							test.push_back(&nodeH);

	mergeInsert(test);
	

	
	return 0;
}
