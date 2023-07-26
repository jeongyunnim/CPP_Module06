#include "ScalarConverter.hpp"

double	ScalarConverter::_doubleType = 0;

static void lowercaseString(std::string& formName)
{
	for (std::string::iterator it = formName.begin(); it != formName.end(); it++)
	{
		if ('A' <= *it && *it <= 'Z')
			*it += 32;
	}

}

static void convertToChar(double target)
{
	std::cout << "char: ";
	if (32 <= target && target <= 126)
		std::cout << static_cast<char>(target) << std::endl;
	else
		std::cout << RED << "Non displayable" << RESET << std::endl;
}

static void convertToInt(double target)
{
	std::cout << "int: ";
	if (target > INT32_MAX)
		std::cout << RED << "over the int max value." << RESET << std::endl;
	else if (target < INT32_MIN)
		std::cout << RED << "over the int min value." << RESET << std::endl;
	else
		std::cout << static_cast<int>(target) << std::endl;
}

static bool	stringValidCheck(std::string target)
{
	int dotFlag = 0;
	std::string validStringList[4] = {"nan", "nanf", "inf", "inff"};

	if (target[0] == '+' || target[0] == '-')
		target.erase(0, 1);
	lowercaseString(target);
	for (int i = 0; i < 4; i++)
	{
		if (target == validStringList[i])
		{
			std::cout << target << std::endl;
			return (true);
		}
	}
	if (target[target.size() - 1] == 'f' || target[target.size() - 1] == 'F')
		target.erase(target.size() - 1, 1);
	for (std::string::iterator it = target.begin(); it != target.end(); it++)
	{
		if (std::isdigit(*it) == false)
		{
			if ((*it == '+' || *it == '-') && it == target.begin())
				continue ;
			else if (*it == '.' && ((it == target.begin() || it == (target.end() - 1))))
				return (false);
			else if (*it == '.' && (std::isdigit(*(it - 1)) == false || std::isdigit(*(it + 1)) == false))
				return (false);
			else if (*it == '.' && dotFlag == 0)
				dotFlag += 1;
			else
				return (false);
		}
	}
	return (true);
}

void ScalarConverter::stringToOtherType(std::string& target)
{
	try
	{
		_doubleType = std::stod(target);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
		return ;
	}
	if (_doubleType != _doubleType || _doubleType == INFINITY || _doubleType == -INFINITY)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		convertToChar(_doubleType);
		convertToInt(_doubleType);
	}
	std::cout << std::fixed << "float: "  << std::setprecision(1) << static_cast<float>(_doubleType) << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << _doubleType << std::endl;
}

void ScalarConverter::charToOtherType(char target)
{
	if (std::isprint(target) == true)
		std::cout << "char: " << target << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(target) << std::endl;
	std::cout << std::fixed << "float: " << std::setprecision(1) << static_cast<float>(target) << 'f' << std::endl;
	std::cout << "double: " << std::setprecision(1) << static_cast<double>(target) << std::endl;
}


void ScalarConverter::convert(std::string target)
{
	if (target.size() == 0)
		std::cerr << RED << "Error: Empty string error" << std::endl;
	else if (target.size() == 1 && std::isdigit(target[0]) == false)
		charToOtherType(target[0]);
	else
	{
		if (stringValidCheck(target) == false)
		{	
			std::cerr << RED << "Error: Invalid string error" << RESET << " [input: " << target << ']' << std::endl;
			return ;
		}
		stringToOtherType(target);
	}
}
