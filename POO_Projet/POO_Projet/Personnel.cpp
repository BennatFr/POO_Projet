#include "Personnel.h"

using namespace System;

Personnel::Personnel(){
	this->personnel = gcnew DB_Personnel();
	this->address = gcnew Address();
	this->people = gcnew DB_People();
}

Personnel::Personnel(int ID_Personnel){
	this->address = gcnew Address(ID_Personnel, false);

	//SELECT Personnel.ID_People, Personnel.ID_Personnel, Personnel.hire_Date, people.last_Name, People.first_Name FROM Personnel INNER JOIN People ON Personnel.ID_People = People.ID_People
	System::String^ sqlRequest = "SELECT Personnel.ID_Personnel, Personnel.ID_People, Personnel.ID_Superior, Personnel.ID_Address, Personnel.hire_Date, people.last_Name, People.first_Name FROM (SELECT * FROM Personnel WHERE ID_Personnel = "+ ID_Personnel +") AS Personnel INNER JOIN People ON Personnel.ID_People = People.ID_People";
	Row^ result = connection->selectRow(sqlRequest, "Personnel",0);
	//int ID_Personnel, System::String^ hire_Date, int ID_Address, int ID_Superior, int ID_People
	this->personnel = gcnew DB_Personnel(result->getInt(0), result->getString(4), result->getInt(3), result->getInt(2), result->getInt(1));
	//int ID_People, System::String^ last_Name, System::String^ first_Name
	this->people = gcnew DB_People(result->getInt(1), result->getString(5), result->getString(6));
}

int Personnel::getPersonnelID() {
	return this->personnel->getIDPersonnel();
}

DB_Personnel^ Personnel::getPersonnel() {
	return this->personnel;
}

Address^ Personnel::getAddress()
{
	return this->address;
}

DB_People^ Personnel::getPeople() {
	return this->people;
}

void Personnel::setPersonnel(DB_Personnel^ personnel) {
	this->personnel = personnel;
}

void Personnel::setAddress(Address^ address)
{
	this->address = address;
}

void Personnel::setPeople(DB_People^ people) {
	this->people = people;
}


void Personnel::setIDPeople(int ID_People) {
	this->getPeople()->setIDPeople(ID_People);
	this->getPersonnel()->setIDPeople(ID_People);
}

void Personnel::setIDAddress(int ID_Address) {
	this->getPersonnel()->setIDAddress(ID_Address);
	this->getAddress()->setIDAddress(ID_Address);
}

int Personnel::insert() {
	this->getAddress()->insert();
	this->setIDAddress(this->getAddress()->getAddress()->getIDAddress());
	System::String^ sqlRequest;

	if (this->getPeople() != nullptr) {
		sqlRequest = "INSERT INTO People VALUES ('" + this->getPeople()->getLastName() + "', '" + this->getPeople()->getFirstName() + "')";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM People ORDER BY ID_People DESC";
		Row^ result = connection->selectRow(sqlRequest, "People", 0);
		this->setIDPeople(result->getInt(0));
	}

	if (this->getPersonnel() != nullptr) {
		sqlRequest = "INSERT INTO Personnel VALUES ('" + this->getPersonnel()->getHireDate() + "', " + this->getPersonnel()->getIDAddress() + ", " + this->getPersonnel()->getIDSuperior() + ", " + this->getPersonnel()->getIDPeople() + ")";
		connection->execute(sqlRequest);
		sqlRequest = "SELECT TOP 1 * FROM Personnel ORDER BY ID_Personnel DESC";
		Row^ result = connection->selectRow(sqlRequest, "Personnel", 0);
		this->getPersonnel()->setIDPersonnel(result->getInt(0));
	}
	return 0;
}

int Personnel::update() {
	this->getAddress()->update();
	this->setIDAddress(this->getAddress()->getAddress()->getIDAddress());
	System::String^ sqlRequest;

	if (this->getPeople() != nullptr) {
		sqlRequest = "UPDATE People SET last_Name = '" + this->getPeople()->getLastName() + "', first_name = '" + this->getPeople()->getFirstName() + "' WHERE ID_People = " + this->getPeople()->getIDPeople();
		connection->execute(sqlRequest);
	}

	if (this->getPersonnel() != nullptr) {
		sqlRequest = "UPDATE Personnel SET hire_Date = '" + this->getPersonnel()->getHireDate() + "', ID_Address = " + this->getPersonnel()->getIDAddress() + ", ID_People = " + this->getPersonnel()->getIDPeople() + ", ID_Superior = " + this->getPersonnel()->getIDSuperior() + " WHERE ID_Personnel = " + this->getPersonnel()->getIDPersonnel();
		connection->execute(sqlRequest);
	}
	return 0;
}
