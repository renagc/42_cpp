#include "Array.tpp"

int main(void)
{
	try
	{
		Array<int> intArray(5);
		for (unsigned int i = 0; i < intArray.size(); ++i)
			intArray[i] = i * 10;
		std::cout << "Printing integer array:" << std::endl;
		intArray.print();
		std::cout << "Accessing elements using subscript operator:" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		std::cout << "Accessing invalid element using subscript operator:" << intArray[6] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		const Array<std::string> stringArray(3);
		stringArray[0] = "Element1";
		stringArray[1] = "Element2";
		stringArray[2] = "Element3";
		std::cout << "Printing character array:" << std::endl;
		stringArray.print();
		std::cout << "Accessing elements using subscript operator on const object:" << std::endl;
		for (unsigned int i = 0; i < stringArray.size(); ++i)
			std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
		std::cout << "Accessing invalid element using subscript operator:" << stringArray[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		const Array<float> floatArray;
		floatArray[0] = 30.45;
		std::cout << "Printing character array:" << std::endl;
		floatArray.print();
		std::cout << "Accessing elements using subscript operator on const object:" << std::endl;
		for (unsigned int i = 0; i < floatArray.size(); ++i)
			std::cout << "floatArray[" << i << "] = " << floatArray[i] << std::endl;
		std::cout << "Accessing invalid element using subscript operator:" << floatArray[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;
}