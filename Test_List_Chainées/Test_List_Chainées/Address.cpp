#include "Address.h"

Address::Address()
{
    this->number = 0;
}

Address::Address(int i)
{
    this->number = i;
}

int Address::getNumber()
{
    return this->number;
}

void Address::setNumber(int number)
{
    this->number = number;
}
