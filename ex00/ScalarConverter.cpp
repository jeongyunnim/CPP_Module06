#include "ScalarConverter.hpp"

static std::string convertToInt(double target)
{
	std::string result;

	if (target > INT32_MAX || target > INT32_MAX)
	return (result);
}

void ScalarConverter::stringToOtherType(std::string& target)
{

}

void ScalarConverter::charToOtherType(char target)
{
	if (std::isprint(target) == true)
		std::cout << "char: " << target << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(target) << std::endl;
	std::cout << "float: " << static_cast<float>(target) << std::endl;
	std::cout << "double: " << static_cast<double>(target) << std::endl;
}


void ScalarConverter::convert(std::string target)
{
	if (target.size() == 0)
		std::cerr << RED << "Error: Empty string error" << std::endl;
	else if (target.size() == 1 && std::isdigit(target[0]) == false)
	{
		charToOtherType(target[0]);
	}
	else
	{
		stringToOtherType(target);
	}
}
