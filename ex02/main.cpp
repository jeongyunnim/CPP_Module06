#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data *test = new Data;
	Data *dataPtr;
	uintptr_t	dataSerial;

	std::cout << BOLDWHITE << "-----------------------<<serialize and deserialize test>>-----------------------\n" << RESET << std::endl;
	test->content = "Hello evaluator";
	std::cout << "Original data's content: "<< test->content << '\n' << std::endl; 

	std::cout << "data pointer: " << CYAN << test << RESET << std::endl;
	dataSerial = Serializer::serialize(test);
	std::cout << "data pointer's serial number: " << dataSerial << std::endl;
	dataPtr = Serializer::deserialize(dataSerial);
	std::cout << "returned data pointer: " << CYAN << test << RESET << std::endl;
	std::cout << BOLDWHITE << "\n-----------------------<<Deserialized pointer's value>>-----------------------\n" << RESET << std::endl;
	std::cout << "Data pointer's content: " << dataPtr->content << std::endl;

	std::cout << BOLDWHITE << "\n-----------------------<<Delete whth desireailized pointer>>-----------------------\n" << RESET << std::endl;
	delete dataPtr;
	std::cout << "THANK YOU!" << std::endl;
	return (0);
}