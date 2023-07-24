#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
	:	_doubleType(0)
	,	_floatType(0)
	,	_intType(0)
	,	_charType(0)
{}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	_doubleType = rhs._doubleType;
	_floatType = rhs._floatType;
	_intType = rhs._intType;
	_charType = rhs._charType;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

// bool	ScalarConverter::stringToOtherType(std::string& target)
// {
// 	std::stringstream targetStream;

// 	targetStream.str(target);
// 	targetStream >> _doubleType;

// 	if (targetStream.fail() || targetStream.eof() == false)
// 	{
// 		return (false);
// 	}

// 	if (target[0] == '+' || target[0] == '-' || isalnum(target[0]) == true)
// 	{
// 		// {num}, +{num}, -{num}, +inf, +inff, -inf, -inff, nan, nanf
// 	}
// 	else
// 	{
// 		// {single character}
// 		if (target.size() != 1)
// 		{
// 			return (false);
// 		}
// 		return (true);
// 	}
// }

void ScalarConverter::convert(std::string target)
{
	if (target.size() == 0)
	{
		std::cerr << RED << "Error: String is empty" << RESET << std::endl;
		return ;
	}
	else if (target.size() == 1)
	{
		if (std::isprint(target[0]) == true)
			_charType = target[0];
		else
			_charType = NON_PRINTABLE;
		
	}
	if (stringToOtherType(target) == false)
	{
		std::cerr << "Input: " << target << RED << " Error: Invalid string error" << RESET << std::endl;
		return ;
	}
	
}
