#include "utilities.hpp"

Base *generate(void)
{
	struct timeval *timeTemp = new struct timeval();
	for (int i = 0; i < 30; i++)
		gettimeofday(timeTemp, NULL);
	std::srand(timeTemp->tv_usec);
	delete timeTemp;
	
	if (std::rand() % 3 == 0)
		return (new A());
	else if (std::rand() % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	Base *baseIdentifier;

	std::cout << BOLDWHITE << "<pointer>" << RESET << std::endl;
	if (p == NULL)
		std::cerr << RED << "Error: Null pointer error" << RESET << std::endl;
	baseIdentifier = dynamic_cast<A *>(p);
	if (baseIdentifier != NULL)
		std::cout << p << CYAN << " is A" << RESET << std::endl;
	baseIdentifier = dynamic_cast<B *>(p);
	if (baseIdentifier != NULL)
		std::cout << p << GREEN << " is B" << RESET << std::endl;
	baseIdentifier = dynamic_cast<C *>(p);
	if (baseIdentifier != NULL)
		std::cout << p << MAGENTA << " is C" << RESET << std::endl;
}

void identify(Base& p)
{
	std::cout << BOLDWHITE << "<reference>" << RESET << std::endl;
	try
	{
		A& AIdentifier = dynamic_cast<A &>(p);
		std::cout << &AIdentifier << CYAN << " is A" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B& BIdentifier = dynamic_cast<B &>(p);
		std::cout << &BIdentifier << GREEN << " is B" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& CIdentifier = dynamic_cast<C&>(p);
		std::cout << &CIdentifier << MAGENTA << " is C" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
