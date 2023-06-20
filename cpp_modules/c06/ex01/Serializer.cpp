#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

/*
    1. reinterpret_cast can perform dangerous conversions because it can typecast any pointer to any other pointer.
    2. reinterpret_cast is used when you want to work with bits.
    3. The result of a reinterpret_cast cannot safely be used for anything other than being cast back to its original type.
    4. we should be very careful when using this cast.
    5. if we use this type of cast then it becomes non-portable product.
*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
