#include "add.h"

add::add()
{
	this->a = 1;
	this->b = 2;
}

add::add(int a, int b)
{
	this->a = a;
	this->b = b;
}

int add::addd()
{
	return this->a+ this->b;
}
