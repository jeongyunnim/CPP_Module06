#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./[program name] [argument]" << RESET << std::endl;
		return (1);
	}

	std::stringstream stringStreamForTest;

	int testInt = 0;
	float testFloat = 0;

	stringStreamForTest.str(argv[1]);
	std::cout << "original string: " << stringStreamForTest.str() << std::endl;

	stringStreamForTest.str(argv[1]);
	stringStreamForTest >> testInt;
	std::cout << "int: " << testInt << std::endl;

	// stringStreamForTest.clear();
	stringStreamForTest.str(argv[1]);
	std::cout << "original string: " << stringStreamForTest.str() << std::endl;
	stringStreamForTest >> testFloat;
	std::cout << "float: " << testFloat << std::endl;


    std::stringstream ss(argv[1]);
    ss >> testFloat;

    if (ss.fail()) {
        std::cout << "Failed to convert the string to float." << std::endl;
    }
    else {
        std::cout << "Float value: " << testFloat << std::endl;
    }
	return (0);
}