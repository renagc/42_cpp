#include "Serializer.hpp"
#include "Data.hpp"

//static_cast = convert between types using a combination of implicit and user-defined conversions (compile time)
//dynamic_cast = used for safely downcast polimorphism (runtime)
//const-cast = add or remove constness of a variable
//reinterpret_cast = convert between types by reinterpreting the variable (unsafe)

int main()
{
    Data myData(42);
	std::cout << &myData << std::endl;
    uintptr_t serializedPtr = Serializer::serialize(&myData);
	std::cout << serializedPtr << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);
	std::cout << deserializedPtr << std::endl;
    if (deserializedPtr == &myData) {
        std::cout << "Serialization and deserialization successful." << std::endl;
        std::cout << "Original Data value: " << myData.getDataValue() << std::endl;
    } else {
        std::cerr << "Serialization and deserialization failed." << std::endl;
    }

    return 0;
}