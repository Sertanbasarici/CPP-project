#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.number = 42;
    myData.text = "Hello serialization!";

    std::cout << "Original address: " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << deserialized << std::endl;

    if (deserialized == &myData)
        std::cout << "Deserialization successful!" << std::endl;
    else
        std::cout << "Deserialization failed!" << std::endl;

    std::cout << "Number: " << deserialized->number << std::endl;
    std::cout << "Text: " << deserialized->text << std::endl;

    return 0;
}
