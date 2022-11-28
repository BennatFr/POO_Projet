#include "DB_People.h"

DB_People::DB_People()
{
	this->ID_People = 0;
	this->last_Name = "";
	this->first_Name = "";
}

DB_People::DB_People(int ID_People, System::String^ last_Name, System::String^ first_Name)
{
	this->ID_People = ID_People;
	this->last_Name = last_Name;
	this->first_Name = first_Name;
}

int DB_People::getIDPeople()
{
	return this->ID_People;
}

System::String^ DB_People::getLastName()
{
	return this->last_Name;
}

System::String^ DB_People::getFirstName()
{
	return this->first_Name;
}

void DB_People::setIDPeople(int ID_People)
{
	this->ID_People = ID_People;
}

void DB_People::setLastName(System::String^ last_Name)
{
	this->last_Name = last_Name;
}

void DB_People::setFirstName(System::String^ first_Name)
{
	this->first_Name = first_Name;
}
