#include "utilities.hpp"

void leak()
{
	system("leaks $PPID");
}
void testReferenceType(Base *target[], int i)
{
	Base& temp = *target[i];
	std::cout << i + 1 << ": ";
	identify(temp);
}

int main(void)
{
	int	time = 20;
	Base *generatedClasses[time];

	atexit(leak);
	bzero(generatedClasses, sizeof(generatedClasses));
	std::cout << BOLDWHITE << "-----------------------<<Generate random class>>-----------------------\n" << RESET << std::endl;
	for (int i = 0; i < time; i++)
	{
		generatedClasses[i] = generate();
	}
	std::cout << BOLDWHITE << "\n\n-----------------------<<identify random class>>-----------------------\n" << RESET << std::endl;
	for (int i = 0; i < time; i++)
	{
		std::cout << '\n' << i + 1 << ": ";
		identify(generatedClasses[i]);
		testReferenceType(generatedClasses, i);
	}

	for (int i = 0; i < time; i++)
	{
		if (generatedClasses[i] != NULL)
			delete generatedClasses[i];

	}

	return (0);
	std::cout << "1: ";
}