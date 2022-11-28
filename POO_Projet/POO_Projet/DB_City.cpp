#include "DB_City.h"

DB_City::DB_City()
{
	this->ID_City = 0;
	this->name = "";
	this->postal_number = "";
}

DB_City::DB_City(int ID_City, System::String^ name, System::String^ postal_number)
{
	this->ID_City = ID_City;
	this->name = name;
	this->postal_number = postal_number;
}

int DB_City::getIDCity() {
	return this->ID_City;
}

System::String^ DB_City::getName() {
	return this->name;
}

System::String^ DB_City::getPostalNumber() {
	return this->postal_number;
}

void DB_City::setIDCity(int ID_City)
{
	this->ID_City = ID_City;
}

void DB_City::setName(System::String^ name)
{
	this->name = name;
}

void DB_City::setPostalNumber(System::String^ postal_number)
{
	this->postal_number = postal_number;
}

bool DB_City::verifName(System::String^ name)
{
	throw gcnew System::NotImplementedException();
}

bool DB_City::verifPostalNumber(System::String^ postal_number)
{
	throw gcnew System::NotImplementedException();
}
