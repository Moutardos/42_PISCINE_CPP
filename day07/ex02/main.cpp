#include <iostream>
#include <string>
#include "Array.hpp"

int	main(void)
{
	{
		Array<int>	arrayInt(15);
		
		for (int i = 0; i < 15; ++i)
			arrayInt[i] = i < 2 ? 1 : arrayInt[i - 2] + arrayInt[i - 1];
		for (int i = 0; i < 15; ++i)
			std::cout << arrayInt[i] << " ";
		std::cout << std::endl << std::endl;
	}
	{
		Array<std::string>	arrayString(4);
		Array<std::string>	arrayString2;
		
		arrayString[1] = "J'aurais";
		arrayString[2] = "besoin";
		arrayString[3] = "d'aide";

	
		arrayString2 = arrayString;
		arrayString2[0] = "Salut,";
		
		for (int i = 0; i < 4; ++i)
			std::cout << arrayString[i] << " ";
		std::cout << "\n";
		for (int i = 0; i < 4; ++i)
			std::cout << arrayString2[i] << " ";
		std::cout << std::endl;

		try
		{
			arrayString[4] = "NOOOOOO";
		}
		catch (std::out_of_range &exception)
		{
			std::cout << "Exception: " << exception.what() << std::endl;
		}
	}
}

//#include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }