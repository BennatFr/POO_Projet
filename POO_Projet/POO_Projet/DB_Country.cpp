#include "DB_Country.h"

DB_Country::DB_Country() {
	this->ID_Country = 0;
	this->name = "";
}

DB_Country::DB_Country(int ID_Country, System::String^ name) {
	this->ID_Country = ID_Country;
	this->name = name;
}

DB_Country::~DB_Country() {
	delete name;
}

int DB_Country::getIDCountry() {
	return this->ID_Country;
}

System::String^ DB_Country::getName()
{
	return this->name;
}

void DB_Country::setIDCountry(int ID_Country)
{
	this->ID_Country = ID_Country;
}

void DB_Country::setName(System::String^ name)
{
	this->name = name;
}

bool DB_Country::verifName(System::String^ name)
{
	throw gcnew System::NotImplementedException();
}
