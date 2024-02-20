#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		// std::cout << numbers[i] << std::endl;
    }
    delete [] mirror;//
    return 0;
}

// #define MAX_VALUE 777

// int	main()
// {
// 	srand(time(0));

// 	Array<int>	intArray(7);

// 	std::cout << "Int Array size : " << intArray.size() << std::endl;
// 	for (unsigned int i = 0; i < (intArray.size()); i++)
// 		intArray[i] = rand() % 100;
// 	for (unsigned int i = 0; i < (intArray.size()); i++)
// 		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
// 	std::cout << std::endl;

// 	Array<int>	copyConArray(intArray);

// 	std::cout << "Copy Constructed Array size : " << copyConArray.size() << std::endl;
// 	for (unsigned int i = 0; i < (intArray.size()); i++)
// 		std::cout << "copyConArray[" << i << "] = " << copyConArray[i] << std::endl;
// 	std::cout << std::endl;

// 	Array<int>	copyOpArray = copyConArray;

// 	std::cout << "Copy Assigned Array size : " << copyOpArray.size() << std::endl;
// 	for (unsigned int i = 0; i < copyOpArray.size(); i++)
// 		std::cout << "copyOpArray[" << i << "] = " << copyOpArray[i] << std::endl;
// 	std::cout << std::endl;

// 	Array<int>	maxArray(MAX_VALUE);

// 	std::cout << "Max Value Array size : " << maxArray.size() << std::endl;
// 	for (unsigned int i = 0; i < maxArray.size(); i++)
// 		maxArray[i] = rand() % 100;
// 	try
// 	{
// 		maxArray[-1] = -42;
// 	}
// 	catch(const std::exception& ex)
// 	{
// 		std::cerr << ex.what() << '\n';
// 	}
// 	try
// 	{
// 		maxArray[MAX_VALUE] = 42;
// 	}
// 	catch (std::exception& ex)
// 	{
// 		std::cout << ex.what() << "\n";
// 	}
// 	try
// 	{
// 		Array<int>	negativeArray(-MAX_VALUE);
// 		std::cout << negativeArray.size() << std::endl;
// 	}
// 	catch (std::exception& ex)
// 	{
// 		std::cout << ex.what() << "\n";
// 	}

// 	return 0;
// }
