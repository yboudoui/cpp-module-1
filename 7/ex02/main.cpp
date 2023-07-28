#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int>	ints(10);

	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = i * 2;

	try {
		std::cout << ints[42] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << ints[-42] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << ints[i] << " ";
	std::cout << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
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
        numbers[i] = std::rand();
    }
    delete [] mirror;//
    return 0;
}
